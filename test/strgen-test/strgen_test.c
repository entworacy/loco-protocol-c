#include "../../strgen.h"

int main() 
{
    char *target = malloc(16);
    int result = make_xvc_key(target, "Kt/10.3.2 An/10 ko", "example@example.com");
    printf("Result  Length: %d\n", result);
    printf("Result Data: %s\n", target);
    if(result != 0)
        return 0;
    return 0x08;
}