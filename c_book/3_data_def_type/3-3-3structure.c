#include <stdint.h>
#include <stdio.h>
int main()
{
    struct S
    {
        int32_t a, b;
    } s;
    // } s = {.a = 100, .b = 200}; //所谓初始化是指声明一个对象后，立即用=初始化赋值。如果声明时未初始化，那么在此之后就不能在用初始化器对其初始化了；

    s = (struct S){
        .b = 1,
        .a = 101,
    };
    printf("s.a = %d, s.b = %d\n", s.a, s.b); // s.a = 101, s.b = 1
    s = (struct S){
        99,
        2,
    };
    printf("s.a = %d, s.b = %d\n", s.a, s.b); // s.a = 99, s.b = 2
    ((struct S){10, 20}).a += 10;             // 也可以这样花里胡哨的操作，尽管没有什么实践意义

    struct Test
    {
        int32_t a;
        struct
        {
            int32_t b;
            int32_t c;
            // short int c;
        };
        float d;
    } t = {.a = 1, .b = 2, .c = 3, .d = 10.1};
    printf("t.a = %d, t.b = %d\n", t.a, t.b);
    printf("t.c = %d, t.d = %f\n", t.c, t.d);

    printf("t.c的字节为长度：%d", sizeof(t.c));
}