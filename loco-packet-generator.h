#pragma once

#include "loco-protocol-cxx.h"
#include <libbson-1.0/bson.h>

typedef struct CTX_PACKET {
    unsigned int curr_packet_id;
    bson_t bson_data;
} LOCO_PACKET_CTX;

LOCO_PACKET_CTX *packet_generator_init();
void reset_bson(LOCO_PACKET_CTX *ctx);
struct packet *make_default_loco_packet(LOCO_PACKET_CTX *ctx, char *method);