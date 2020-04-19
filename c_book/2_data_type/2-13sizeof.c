#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 10;
    int array[a + argc];
    size_t size = sizeof(array);
    printf("%u\n", size); //输出44
    size = sizeof(++a);

    //仅会生成对应sizeof操作符的结果相关代码，并不会生成作为sizeof操作数的表达式的代码
    //a仍然是10 ++a没有被执行
    printf("size = %u,a = %d\n", size, a); //size = 4,a= 10
    ++a;
    printf("a=%d\n", a); //a=11

    double d = 10.05;
    size = sizeof d;                  //可以省略圆括号但是最好加上有利代码阅读
    printf("sizeof d = %u \n", size); //sizeof d = 8

    size = sizeof a + sizeof d;
    printf("size = %u\n", size); // size = 12
}