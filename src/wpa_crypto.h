// Criptografía del saludo WPA2-PSK de 4 vías: HMAC-SHA1, PRF de 802.11,
// MIC de EAPOL y desenvolvido de claves AES (RFC 3394). Compila tanto en el
// kernel (SHA1 de libkern) como en espacio de usuario para las pruebas.
#pragma once
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void wpa_hmac_sha1(const uint8_t *key, size_t keyLen,
                   const uint8_t *const *data, const size_t *lens, int n,
                   uint8_t out[20]);

// PRF-n de IEEE 802.11 (11.6.1.2): HMAC-SHA1(key, label || 0 || data || i).
void wpa_prf(const uint8_t *key, size_t keyLen, const char *label,
             const uint8_t *data, size_t dataLen, uint8_t *out, size_t outLen);

// PTK de 48 bytes (KCK 16 | KEK 16 | TK 16) para CCMP.
void wpa_derive_ptk(const uint8_t pmk[32], const uint8_t aa[6], const uint8_t spa[6],
                    const uint8_t anonce[32], const uint8_t snonce[32], uint8_t ptk[48]);

// MIC de EAPOL-Key versión 2: HMAC-SHA1-128 sobre la trama con el MIC en cero.
void wpa_eapol_mic(const uint8_t kck[16], const uint8_t *frame, size_t len, uint8_t mic[16]);

void aes128_decrypt_block(const uint8_t key[16], const uint8_t in[16], uint8_t out[16]);

// RFC 3394. Devuelve 0 si la verificación de integridad (A6A6...) es correcta.
int aes_unwrap(const uint8_t kek[16], const uint8_t *cipher, size_t cipherLen, uint8_t *plain);

#ifdef __cplusplus
}
#endif
