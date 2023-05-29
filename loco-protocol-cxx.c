#include "loco-protocol-cxx.h"

/// @brief Serializes the 'packet' Struct into bytes that can be sent over the network.
/// @param packet 
/// @param bytes 
/// @return Byte length of converted packet
int serialize_packet(struct packet *packet, char *bytes) {
  int bytes_written = 0;

  int32_t packet_id = packet->packet_id;
  memcpy(bytes + bytes_written, &packet_id, sizeof(int32_t));
  bytes_written += sizeof(int32_t);
  uint16_t status_code = packet->status_code;
  memcpy(bytes + bytes_written, &status_code, sizeof(uint16_t));
  bytes_written += sizeof(uint16_t);
  memcpy(bytes + bytes_written, packet->method, sizeof(packet->method));
  bytes_written += sizeof(packet->method);
  uint8_t body_type = packet->body_type;
  memcpy(bytes + bytes_written, &body_type, sizeof(uint8_t));
  bytes_written += sizeof(uint8_t);
  int32_t body_length = packet->body_length;
  memcpy(bytes + bytes_written, &body_length, sizeof(int32_t));
  bytes_written += sizeof(int32_t);
  memcpy(bytes + bytes_written, packet->body, packet->body_length);
  bytes_written += packet->body_length;

  return bytes_written;
}

int serialize_handshake_packet(struct secure_handshake_packet *packet, char *bytes) {
  int bytes_written = 0;

  uint32_t encrypted_data_length = packet->encrypted_data_length;
  memcpy(bytes + bytes_written, &encrypted_data_length, sizeof(uint32_t));
  bytes_written += sizeof(uint32_t);
  uint32_t handshake_type = packet->handshake_type;
  memcpy(bytes + bytes_written, &handshake_type, sizeof(uint32_t));
  bytes_written += sizeof(uint32_t);
  uint32_t encrypt_type = packet->encrypt_type;
  memcpy(bytes + bytes_written, &encrypt_type, sizeof(uint32_t));
  bytes_written += sizeof(uint32_t);
  memcpy(bytes + bytes_written, packet->encrypted_data, packet->encrypted_data_length);
  bytes_written += packet->encrypted_data_length;

  return bytes_written;
}

struct packet *deserialize_packet(char *bytes) {
  struct packet *packet = (struct packet *)malloc(sizeof(struct packet));
  if(init_packet(packet) < 0) return NULL;
  if (packet == NULL) {
    return NULL;
  }
  packet->packet_id = *(int32_t *)bytes;
  bytes += sizeof(int32_t);
  packet->status_code = *(uint16_t *)bytes;
  bytes += sizeof(uint16_t);
  strncpy(packet->method, bytes, sizeof(packet->method));
  bytes += sizeof(packet->method);
  packet->body_type = *(uint8_t *)bytes;
  bytes += sizeof(uint8_t);
  packet->body_length = *(uint32_t *)bytes;
  bytes += sizeof(uint32_t);
  packet->body = (char*) malloc(packet->body_length);
  memcpy(packet->body, bytes, packet->body_length);

  return packet;
}

int init_packet(struct packet* packet) {
    if(packet == NULL) return -1;
    memset(packet->method, '\0', sizeof(packet->method));
    return 0;
}

int main() {
  printf("hi");
  return 0;
}