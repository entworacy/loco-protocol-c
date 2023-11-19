#include "loco-packet-generator.h"

LOCO_PACKET_CTX *packet_generator_init() 
{
    LOCO_PACKET_CTX *ctx = malloc(sizeof(LOCO_PACKET_CTX));
    ctx->curr_packet_id = 1;
    bson_init(&ctx->bson_data);

    return ctx;
}

void reset_bson(LOCO_PACKET_CTX *ctx)
{
    bson_init(&ctx->bson_data);
}

struct packet *make_default_loco_packet(LOCO_PACKET_CTX *ctx, char *method)
{
    struct packet *protocol_default_packet = (struct packet *) malloc(sizeof(struct packet));
    init_packet(protocol_default_packet);
    protocol_default_packet->packet_id = ctx->curr_packet_id;
    for(int i = 0; i < sizeof(protocol_default_packet->method); i++)
    {
        if(strlen(method) >= i)
        {
            if(method[i] == NULL) 
            {
                //TODO
                protocol_default_packet->method[i] = NULL;
            } else {
                protocol_default_packet->method[i] = method[i];
            }
        } else {
            protocol_default_packet->method[i] = NULL;
        }
    }

    ctx->curr_packet_id++;
    const uint8_t *bson_bytes = bson_get_data(&ctx->bson_data);
    size_t bson_length = ctx->bson_data.len;
    protocol_default_packet->body_length = bson_length;
    protocol_default_packet->body = malloc(protocol_default_packet->body_length);
    memset(protocol_default_packet->body, NULL, protocol_default_packet->body_length);
    for (size_t i = 0; i < bson_length; ++i) {
        protocol_default_packet->body[i] = bson_bytes[i];
    }
    protocol_default_packet->status_code = 0;
    protocol_default_packet->body_type = 0;
    bson_free(bson_bytes);
    return protocol_default_packet;
}