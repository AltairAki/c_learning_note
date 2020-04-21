/**
 *联合体 
 **/
#include <stdint.h>
#include <stdio.h>

int main()
{
    union MyUnion1 {
        int32_t i; // 0000 0000 0000 0000 0000 0001 1000 0000
        int8_t ch; //1000 0000
        int16_t sh;
    } un = {0x180};
    printf("%d\n", un.ch); // 1000 0000

    union {
        int a;
        double b;
        char c;
    } un2 = {.b = 1.1};
    printf("%d\n", un2.a);
    union Myunion3 {
        int a;
        char ch;
    } un3;
    un3 = (union Myunion3){.ch = 127};
    return 0;
}