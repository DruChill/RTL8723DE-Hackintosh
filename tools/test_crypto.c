// Prueba src/wpa_crypto.c contra vectores oficiales. Uso: make test
#include <CommonCrypto/CommonKeyDerivation.h>
#include <stdio.h>
#include <string.h>
#include "../src/wpa_crypto.h"

static int failures;

static void hex(const char *s, uint8_t *out, size_t n)
{
    for (size_t i = 0; i < n; i++)
        sscanf(s + 2 * i, "%2hhx", &out[i]);
}

static void check(const char *name, const uint8_t *got, const char *want, size_t n)
{
    uint8_t w[128];
    hex(want, w, n);
    int ok = memcmp(got, w, n) == 0;
    printf("%-28s %s\n", name, ok ? "OK" : "FALLA");
    failures += !ok;
}

int main(void)
{
    uint8_t out[128], key[32], in[64];

    // FIPS-197 C.1
    hex("000102030405060708090a0b0c0d0e0f", key, 16);
    hex("69c4e0d86a7b0430d8cdb78070b4c55a", in, 16);
    aes128_decrypt_block(key, in, out);
    check("AES-128 descifrado", out, "00112233445566778899aabbccddeeff", 16);

    // RFC 3394 4.1
    hex("1fa68b0a8112b447aef34bd8fb5a7b829d3e862371d2cfe5", in, 24);
    int r = aes_unwrap(key, in, 24, out);
    check("AES key unwrap", out, "00112233445566778899aabbccddeeff", 16);
    in[0] ^= 1;
    printf("%-28s %s\n", "unwrap detecta corrupción", aes_unwrap(key, in, 24, out) ? "OK" : "FALLA");
    failures += r != 0;

    // RFC 2202 test case 1
    memset(key, 0x0b, 20);
    const uint8_t *d[1] = {(const uint8_t *)"Hi There"};
    size_t l[1] = {8};
    wpa_hmac_sha1(key, 20, d, l, 1, out);
    check("HMAC-SHA1 (RFC 2202)", out, "b617318655057264e28bc0b6fb378c8ef146be00", 20);

    // IEEE 802.11i H.3, test case 1 (PRF-512)
    wpa_prf(key, 20, "prefix", (const uint8_t *)"Hi There", 8, out, 64);
    check("PRF-512 (802.11i H.3)", out,
          "bcd4c650b30b9684951829e0d75f9d54b862175ed9f00606e17d8da35402ffee"
          "75df78c3d31e0f889f012120c0862beb67753e7439ae242edb8373698356cf5a", 64);

    // IEEE 802.11i H.4, test case 1 (PSK de la contraseña)
    CCKeyDerivationPBKDF(kCCPBKDF2, "password", 8, (const uint8_t *)"IEEE", 4,
                         kCCPRFHmacAlgSHA1, 4096, out, 32);
    check("PBKDF2 PMK (802.11i H.4)", out,
          "f42c6fc52df0ebef9ebb4b90b38a5f902e83fe1b135a70e23aed762e9710a12e", 32);

    printf(failures ? "\n%d pruebas fallaron\n" : "\nTodo correcto\n", failures);
    return failures != 0;
}
