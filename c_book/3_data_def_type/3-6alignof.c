#include <stdalign.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/**
 * _ Alignof 关键字 来 查看 当前 指定 对象 的 对齐 要求。

 * 在 C 语言 中， 每个 完整 的 对象 类型 都 具有 对齐 要求。 所谓 N 字节 对齐 是指 分配 该 对象 存储 空间 时， 其 起始 地址 必须 是 N 字节 的 倍数。 比如， 一个 对象 要求 4 字节 对齐 则 意味着 给 该 对象 分配 的 起始 地址 必须 能被 4 整除。
 **/
int main()
{
    size_t a = _Alignof(max_align_t); // 当前编译器的最大对齐字节数
    printf("%u\n", a);                // 16

    size_t b = alignof(bool); //查询 布尔 类型 的 对齐 字节数
    printf("%u\n", b);        // 1

    size_t c = alignof(int); //查询 int 类型 的 对齐 字节数
    printf("%u\n", c);       // 4

    size_t d = alignof(short); //查询 short 类型 的 对齐 字节数
    printf("%u\n", d);         // 2

    struct S
    {
        char a;
        short b;
        int c;
        // float f;
        // double d;
        // long double ld;
    } s = {0, 1, 2};
    size_t size1 = alignof(struct S);
    printf("%u\n", size1); //16
    size_t size2 = sizeof(s);
    printf("%u\n", size2); //32
}