#pragma once
#include <memory.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <openssl/rand.h>
#include <openssl/aes.h>

const int AES_KEY_LENGTH = 128 / 8; // AES-KEY LENGTH

typedef enum _CRYPTO_MODULE_RESULT {
  RANDOM_FAILED = -4,
  ENCRYPT_FAILED,
  DECRYPT_FAILED,
  RSA_ERROR,
  SUCCESS
} CRYPTO_RESULT;

struct packet {
  int32_t packet_id;
  uint16_t status_code;
  char method[11];
  uint8_t body_type;
  int32_t body_length;
  char* body;
};

struct secure_handshake_packet {
    uint32_t encrypted_data_length;  // <-- Encrypted_data length
    uint32_t handshake_type;
    uint32_t encrypt_type;
    char* encrypted_data;
};

int serialize_handshake_packet(struct secure_handshake_packet *handshake_packet, char *buffer);
int serialize_packet(struct packet *packet, char *buffer);

/**
 * THIS FUNCTION IS CURRENTLY NOT IMPLEMENTED
 * 
 * I don't think the server will return "secure_handshake_packet" to the client.
 * This is because the definition of Handshake Packet is like that.
 * However, we plan to implement deserialization of "secure_handshake_packet" in the near future as well.
 * Currently, there are many features that need to be added first,
 * so we ask for your patience if you are waiting for deserialization.
 */
__attribute__((unused)) struct secure_handshake_packet *deserialize_handshake_packet(char *bytes);

struct packet *deserialize_packet(char *bytes);

int init_packet(struct packet *packet);

CRYPTO_RESULT __ENC_generate_randomic_aes_key(unsigned char *aes_key_cursor) {
  if(RAND_bytes(aes_key_cursor, AES_KEY_LENGTH) != 1)
    return RANDOM_FAILED;
  return SUCCESS;
}

void __ENC_encrypt_aes_cbc(const unsigned char *aes_key, const unsigned char *target,
    unsigned char *encrypted_data, size_t size) {
  AES_KEY key;
  AES_set_encrypt_key(aes_key, AES_BLOCK_SIZE / 8, &key);
  unsigned char iv[AES_BLOCK_SIZE];
  if(RAND_bytes(iv, sizeof(iv)) != 1)
    printf("RAND_bytes -> iv error"); // TODO
  AES_cbc_encrypt(target, encrypted_data, size, &key, iv, AES_ENCRYPT);
}