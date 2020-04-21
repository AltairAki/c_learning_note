#include <stdalign.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/**
 * 结构体的字节对齐与填充
 * */

int main()
{
    struct S
    {
        int8_t ch;  // 一个字节 - 字节对齐长度为x即1
        int16_t sh; // 两个字节 - 字节对齐长度为y即2
        int32_t i;  // 四个字节 - 字节对齐长度为z即4
        // 还可以通过alignas指定字节对齐长度用法如：
        // int _Alignas(double) a = 0;
        // int alignas(n) a = 0; (其中n为0,1,2,4大于4时必须是4的整数倍，且n有最大可对齐的字节数)
    } st = {
        0x01,
        // [0]  长度1
        //ch 存放在偏移地址0单元处，下一个起始偏移地址单元为1
        0x0101,
        // [0,1][2,3]   长度4
        // 为满足字节对齐，sh的起始偏移量地址必须为最小n*y,所以sh从2开始,因此偏移地址1单元只好补0, 2,3单元两个字节刚好够存放sh，下一个起始偏移地址单元为4
        // 其中n为1,2,3...
        0x01010101};
    // [0,1][2,3][4,5,6,7]  长度8
    // 为满足字节对齐，i的起始偏移量地址必须为最小n*z,正好i从4开始,不用补零，4,5,6,7单元刚好存放4字节的i。
    // 且结构体字节长度8，满足st的最大对齐字节数4的倍数，所以结构体末尾也不需要补0

    //01 (00)  0101  01010101
    printf("%u\n", sizeof(st));

    size_t offset_ch = offsetof(struct S, ch);
    size_t offset_sh = offsetof(struct S, sh);
    size_t offset_i = offsetof(struct S, i);
    //offsetof宏，用于获取当前成员所在的偏移位置。它定义在< stddef.h>头文件中。
    printf("%u,%u,%u\n", offset_ch, offset_sh, offset_i); // 0,2,4

    // 再次验证
    struct
    {
        char a;    //1个字节
        int64_t b; //8个字节
        short c;   //2个字节
    } st2;
    // 占用24个字节
    printf("%u\n", sizeof(st2));
}