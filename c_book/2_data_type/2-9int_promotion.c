/**
 * 一般来说，类型占用字节越多，精度也越高。C语言将整数等级成为整数转换等级。
 * long long int > long int > int > short > signed char == char == unsigned int
 * 
 * 整数晋升
 * 整数晋升是因为低转换等级提升到高转换等级类型，在整数数据上不会有任何变化，而仅仅是类型变为更高等级了。
 **/

#include <stdio.h>

int main()
{
    // 1 bytes -128
    char c = -128;
    // 2 bytes -128
    short s = c;
    // 1 bytes -128
    char cc = s;

    int i = s;

    long int l = i;

    long long int ll = i;

    printf("c的长度:%d bytes,s的长度:%d bytes,cc的长度为：%d\n", sizeof(c), sizeof(s), sizeof(cc));
    //c的长度:1 bytes,s的长度:2 bytes,cc的长度为：1
    printf("i的长度:%d bytes,l的长度:%d bytes,ll的长度为：%d bytes\n", sizeof(i), sizeof(l), sizeof(ll));
    //i的长度:4 bytes,l的长度:4 bytes,ll的长度为：8 bytes

    printf("c的值:%d,s的值:%d,cc的值为：%d\n", c, s, cc);
    //c的值:-128,s的值:-128,cc的值为：-128

    unsigned char a = 255;
    unsigned int u = a;

    printf("a的长度：%d bytes， u的长度：%d bytes", sizeof(a), sizeof(u));
    // a的长度：1 bytes， u的长度：4 bytes
}