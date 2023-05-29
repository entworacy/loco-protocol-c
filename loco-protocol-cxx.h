#pragma once
#include <memory.h>
#include <stdint.h>

struct packet {
  int32_t packet_id;
  uint16_t status_code;
  char method[11];
  uint8_t body_type;
  int32_t body_length;
  char* body;
};

struct secure_handshake_packet {};



int serialize_packet(struct packet *packet, char *buffer);
struct packet *deserialize_packet(const char *bytes);

int init_packet(struct packet *packet);