#include "strgen.h"

int make_xvc_key(char *target, char *ua, char *email) 
{
    if(ua == NULL || email == NULL)
    {
        return 0;
    }

    while(target == NULL)
        target = malloc(16);

    int transfer_text_size = strlen(KAKAO_XVC_TEMPLATE) + strlen(ua) + strlen(email) + 12;
    if(transfer_text_size < 64)
        transfer_text_size = 64;
    
    char *transfer_text = malloc(transfer_text_size);

    sprintf(transfer_text, KAKAO_XVC_TEMPLATE, ua, email);

    SHA512_CTX ctx;
    SHA512_Init(&ctx);
    SHA512_Update(&ctx, transfer_text, strlen(transfer_text));
    SHA512_Final(transfer_text, &ctx);

    if(strlen(transfer_text) == 64)
    {
        printf("transfer text: %s\n", transfer_text);
        char splitted[8] = {NULL, };
        strncpy(splitted, transfer_text, 8);


        for(int i = 0; i < 8; i++) 
        {
            char temp[2];
            sprintf(temp, "%02x", splitted[i] & 0xFF);
            strcat(target, temp);
        } 
        free(transfer_text);
        return strlen(target);
    } else
        return 0;
}

int make_kakaotalk_ua(char *target) 
{
    if (target == NULL) 
    {
        return 0;
    }

    sprintf(target, KAKAOTALK_UA_TEMPLATE, 
        KAKAOTALK_CLIENT_VERSION, 
        ANDROID_BUILD_RELEASE_CODE, 
        ANDROID_DEFAULT_LANGUAGE);
    return 1;
}