#include "../../loco-protocol-cxx.h"
#include "../../loco-packet-generator.h"

int main() {
    struct packet packet;
    int result = init_packet(&packet);
    printf("test start\n\n");
    if(result < 0) {
        printf("[error] init_packet: return value(%d)", result);
        return 0x08; //TEST_ERRORS
    }

    packet.packet_id = 1000;
    packet.status_code = 0;
    strcpy(packet.method, "GETCONF");
    packet.body_type = 0;
    packet.body_length = 13;
    packet.body = (char*) malloc(packet.body_length); //sizeof(char) == 1
    strcpy(packet.body, "Hello, World"); //strncpy ??


    
    char buffer[4000];
    int b_wri = serialize_packet(&packet, buffer);
    struct packet* pack = deserialize_packet(buffer);
    
    printf("Packet ID: %d\n", pack->packet_id);
    free(packet.body);

    LOCO_PACKET_CTX *ctx = packet_generator_init();
    BSON_APPEND_UTF8(&ctx->bson_data, "MCCMNC", "310260");
    BSON_APPEND_UTF8(&ctx->bson_data, "os", "android");
    BSON_APPEND_UTF8(&ctx->bson_data, "model", "SMT975N_31");
    struct packet *packed = make_default_loco_packet(ctx, "GETCONF");
    
    return 0;
}