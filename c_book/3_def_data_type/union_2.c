/*
 * @Descripttion: 
 * @Author: Altair
 * @Date: 2020-04-20 13:45:41
 */
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    union MyUnion {
        int32_t a;
        struct
        {
            int8_t c;
            int16_t b;
        } s;
        float f;
        float ff;
        // char aa;  //输出un2.aa = 100
        // short aa;  //输出un2.aa = 100
        // char aa;  //输出un2.aa = 100
        // int aa;  //输出un2.aa = 100
        // long int aa;  //输出un2.aa = 100
        // long long int aa;  //输出un2.aa = 100
        // unsigned int aa; // 输出un2.aa = 100
        // float aa; // 输出un2.aa = 0
        double aa; // 输出un2.aa = 100
    } un = {.s.b = 0x0201, .s.c = 0x03}, unWarning = {.a = 100, .s.b = -100};
    // } un = {.s.b = 0x0201, .s.c = 0x03};

    printf("union MyUnion 的字节长度为：%u \n", sizeof(un)); // un的字节长度为：8
    //按成员声明顺序，先声明的在低位
    printf("un.a = 0x%.8x\n", un.a); // 输出un.a = 0x02010003

    union MyUnion un2 = {100};
    printf("0x%.8x\n",un2.a); //0x00000064
    printf("un2.s.b = %d\n", un2.s.b);
    printf("un2.a = 0x%x\n", un2.a);
    printf("un2.aa = 0x%x\n", un2.aa);
    // printf("un2.f = %f\n", un2.f);

    union MyUnion un3;
    //联合体复合字面量可直接对 一个联合体对象进行赋值
    un3 = (union MyUnion){.f = 10.5f};
    printf("%f\n", un3.f);  // 10.500000
    printf("%f\n", un3.ff); // 10.500000
    printf("%f\n", un3.a); // 0.000000
}