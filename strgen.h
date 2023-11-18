#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define KAKAOTALK_CLIENT_VERSION "10.4.2"
#define KAKAOTALK_UA_TEMPLATE "Kt/%s An/%s %s"
#define KAKAOTALK_AUTH_HEADER "android/" KAKAOTALK_CLIENT_VERSION "/" ANDROID_DEFAULT_LANGUAGE // new Object[] { "android", "10.4.2", c.g() }
#define ANDROID_BUILD_RELEASE_CODE "12"
#define ANDROID_DEFAULT_LANGUAGE "ko"

// KEVIN/KAKAO_UA/IAN/EMAIL_PARAM/ALLEN: X-VC Key
#define KAKAO_XVC_TEMPLATE "KEVIN/%s/IAN/%s/ALLEN"

int make_xvc_key(char *target, char *ua, char *email);
int make_kakaotalk_ua(char *target);