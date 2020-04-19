/**
 * size_t:sizeof返回的类型。size_ t数据类型都能存放当前系统环境下的一个地址长度（32位/64位）。
 * ptrdiff_t用于两个指针相减后的结果，是带符号的。宽度与size_t一样
 **/

#include <stddef.h>
#include <stdio.h>

int main()
{
    size_t a = sizeof(a);
    printf("%d\b", a); // win10 mingw64 8
    size_t *p = &a;
    int b = 100;
    int *q = &b;

    size_t s1 = (size_t)p;
    size_t s2 = (size_t)q;
    printf("Address of a is:0x%X\n", s1); //Address of a is:0x61FE20
    printf("Address of b is:0x%X\n", s2); //Address of b is:0x61FE1C

    ptrdiff_t diff = (ptrdiff_t)q - (ptrdiff_t)p;
    printf("Address of a minus address of b is :%d\n", diff); //Address of a minus address of b is :-4
}