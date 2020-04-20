#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * 位域：两个位域成员，取其较小字段的类型长度，然后观察他们已占用的比特位个数，如果未超过较小的长度则。放在较小比特位长度内。不够的补0。如果已占用比特超过较小比特位长度则补0直到补齐较小的比特位个数。
 **/
int main(int argc, const char *argv[])
{
    enum MyEnum
    {
        ENUM1,
        ENUM2,
        ENUM3,
    };
    struct Test
    {
        int32_t a : 6;
        int16_t b : 5;
        // int8_t c : 8;
        int8_t c : 5;
        char x : sizeof(enum MyEnum);
        bool y : 1;
        enum MyEnum e : ENUM3;
        // } s = {0x18, 0x0a, 0x77, '\0', true, ENUM3};
    } s = {0x18, 0x0a, 0x07, '\0', true, ENUM3};
    //      (0) 10 1  0000 01110111 (00000) 01010  011000

    //        0101 0000 0111 0111 0000 0010 1001 1000

    //      0101 0000 0011 1010 1001 1000
    //        5 0 3 a 9 8
    printf("The size is %u\n", sizeof(s));

    printf(" The content of s is: 0x%.106x\n", *(uint32_t *)&s);
    // win10 mingw64
    // The size is 12
    // The content of s is: 0x00000018

    // gcc输出
    // The size is 4
    // The content of s is: 0x50770298

    struct Test
    {
        int32_t a : 6;
        int8_t b : 5;
        int8_t c : 5;
        char x : sizeof(int);
        bool y : 1;
        enum MyEnum e : ENUM3;
    } s = {0x18, 0x0a, 0x07, '\0', true, ENUM3};

    // 10 1 0000   00000111 00001010  00011000
    // 0101 0000   00000111 00001010  00011000
    //  5     0     0   7   0    a     1    8
}