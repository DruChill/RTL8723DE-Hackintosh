// Ver wpa_crypto.h. Probado con tools/test_crypto.c contra vectores oficiales.
#include "wpa_crypto.h"

#ifdef KERNEL
#include <libkern/crypto/sha1.h>
#include <string.h>
#else
#include <CommonCrypto/CommonDigest.h>
#include <string.h>
#define SHA1_CTX CC_SHA1_CTX
#define SHA1Init(c) CC_SHA1_Init(c)
#define SHA1Update(c, d, l) CC_SHA1_Update(c, d, (CC_LONG)(l))
#define SHA1Final(o, c) CC_SHA1_Final(o, c)
#endif

void wpa_hmac_sha1(const uint8_t *key, size_t keyLen,
                   const uint8_t *const *data, const size_t *lens, int n,
                   uint8_t out[20])
{
    uint8_t k[64] = {0}, pad[64], inner[20];
    SHA1_CTX ctx;

    if (keyLen > 64) {
        SHA1Init(&ctx);
        SHA1Update(&ctx, key, keyLen);
        SHA1Final(k, &ctx);
    } else {
        memcpy(k, key, keyLen);
    }

    for (int i = 0; i < 64; i++)
        pad[i] = k[i] ^ 0x36;
    SHA1Init(&ctx);
    SHA1Update(&ctx, pad, 64);
    for (int i = 0; i < n; i++)
        SHA1Update(&ctx, data[i], lens[i]);
    SHA1Final(inner, &ctx);

    for (int i = 0; i < 64; i++)
        pad[i] = k[i] ^ 0x5c;
    SHA1Init(&ctx);
    SHA1Update(&ctx, pad, 64);
    SHA1Update(&ctx, inner, 20);
    SHA1Final(out, &ctx);
}

void wpa_prf(const uint8_t *key, size_t keyLen, const char *label,
             const uint8_t *data, size_t dataLen, uint8_t *out, size_t outLen)
{
    uint8_t zero = 0, counter = 0, block[20];
    const uint8_t *parts[4] = {(const uint8_t *)label, &zero, data, &counter};
    size_t lens[4] = {strlen(label), 1, dataLen, 1};

    for (size_t pos = 0; pos < outLen; counter++) {
        wpa_hmac_sha1(key, keyLen, parts, lens, 4, block);
        size_t take = outLen - pos < 20 ? outLen - pos : 20;
        memcpy(out + pos, block, take);
        pos += take;
    }
}

void wpa_derive_ptk(const uint8_t pmk[32], const uint8_t aa[6], const uint8_t spa[6],
                    const uint8_t anonce[32], const uint8_t snonce[32], uint8_t ptk[48])
{
    uint8_t data[6 + 6 + 32 + 32];
    int aaFirst = memcmp(aa, spa, 6) < 0;
    int anFirst = memcmp(anonce, snonce, 32) < 0;

    memcpy(data, aaFirst ? aa : spa, 6);
    memcpy(data + 6, aaFirst ? spa : aa, 6);
    memcpy(data + 12, anFirst ? anonce : snonce, 32);
    memcpy(data + 44, anFirst ? snonce : anonce, 32);
    wpa_prf(pmk, 32, "Pairwise key expansion", data, sizeof(data), ptk, 48);
}

void wpa_eapol_mic(const uint8_t kck[16], const uint8_t *frame, size_t len, uint8_t mic[16])
{
    uint8_t full[20];
    const uint8_t *parts[1] = {frame};
    size_t lens[1] = {len};
    wpa_hmac_sha1(kck, 16, parts, lens, 1, full);
    memcpy(mic, full, 16);
}

// ------------------------------------------------------------ AES-128 (FIPS-197)

static const uint8_t sbox[256] = {
    0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
    0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
    0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
    0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
    0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
    0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
    0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
    0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
    0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
    0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
    0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
    0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
    0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
    0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
    0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
    0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16,
};

static uint8_t xtime(uint8_t x) { return (uint8_t)((x << 1) ^ ((x & 0x80) ? 0x1b : 0)); }

static uint8_t gmul(uint8_t a, uint8_t b)
{
    uint8_t r = 0;
    while (b) {
        if (b & 1)
            r ^= a;
        a = xtime(a);
        b >>= 1;
    }
    return r;
}

static void key_expand(const uint8_t key[16], uint8_t rk[176])
{
    uint8_t rcon = 1;
    memcpy(rk, key, 16);
    for (int i = 16; i < 176; i += 4) {
        uint8_t t[4] = {rk[i - 4], rk[i - 3], rk[i - 2], rk[i - 1]};
        if (i % 16 == 0) {
            uint8_t tmp = t[0];
            t[0] = sbox[t[1]] ^ rcon;
            t[1] = sbox[t[2]];
            t[2] = sbox[t[3]];
            t[3] = sbox[tmp];
            rcon = xtime(rcon);
        }
        for (int j = 0; j < 4; j++)
            rk[i + j] = rk[i - 16 + j] ^ t[j];
    }
}

void aes128_decrypt_block(const uint8_t key[16], const uint8_t in[16], uint8_t out[16])
{
    uint8_t rk[176], s[16], inv[256];
    for (int i = 0; i < 256; i++)
        inv[sbox[i]] = (uint8_t)i;
    key_expand(key, rk);

    for (int i = 0; i < 16; i++)
        s[i] = in[i] ^ rk[160 + i];

    for (int round = 9; round >= 0; round--) {
        // InvShiftRows (estado en orden de columnas: s[c*4 + r])
        uint8_t t[16];
        for (int c = 0; c < 4; c++)
            for (int r = 0; r < 4; r++)
                t[((c + r) % 4) * 4 + r] = s[c * 4 + r];
        // InvSubBytes + AddRoundKey
        for (int i = 0; i < 16; i++)
            s[i] = inv[t[i]] ^ rk[round * 16 + i];
        if (round == 0)
            break;
        // InvMixColumns
        for (int c = 0; c < 4; c++) {
            uint8_t *col = s + c * 4, a0 = col[0], a1 = col[1], a2 = col[2], a3 = col[3];
            col[0] = gmul(a0, 14) ^ gmul(a1, 11) ^ gmul(a2, 13) ^ gmul(a3, 9);
            col[1] = gmul(a0, 9) ^ gmul(a1, 14) ^ gmul(a2, 11) ^ gmul(a3, 13);
            col[2] = gmul(a0, 13) ^ gmul(a1, 9) ^ gmul(a2, 14) ^ gmul(a3, 11);
            col[3] = gmul(a0, 11) ^ gmul(a1, 13) ^ gmul(a2, 9) ^ gmul(a3, 14);
        }
    }
    memcpy(out, s, 16);
}

int aes_unwrap(const uint8_t kek[16], const uint8_t *cipher, size_t cipherLen, uint8_t *plain)
{
    if (cipherLen < 24 || cipherLen % 8)
        return -1;
    size_t n = cipherLen / 8 - 1;
    uint8_t a[8], b[16];

    memcpy(a, cipher, 8);
    memcpy(plain, cipher + 8, n * 8);

    for (int j = 5; j >= 0; j--) {
        for (size_t i = n; i >= 1; i--) {
            uint64_t t = (uint64_t)n * (uint64_t)j + i;
            memcpy(b, a, 8);
            for (int k = 0; k < 8; k++)
                b[7 - k] ^= (uint8_t)(t >> (8 * k));
            memcpy(b + 8, plain + (i - 1) * 8, 8);
            aes128_decrypt_block(kek, b, b);
            memcpy(a, b, 8);
            memcpy(plain + (i - 1) * 8, b + 8, 8);
        }
    }

    for (int k = 0; k < 8; k++)
        if (a[k] != 0xa6)
            return -1;
    return 0;
}
