#include "getconf.h"

struct packet *get_booking_packet(LOCO_PACKET_CTX *ctx) 
{
    if(ctx == NULL) return NULL;
    BSON_APPEND_UTF8(&ctx->bson_data, "MCCMNC", "310260");
    BSON_APPEND_UTF8(&ctx->bson_data, "os", "android");
    BSON_APPEND_UTF8(&ctx->bson_data, "model", "SMT975N_31");
    struct packet *packet = make_default_loco_packet(ctx, "GETCONF");
    
    return packet;
}