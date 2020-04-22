/*
 * @Descripttion: 联合体
 * 联合体与结构体的命名方式与基本用法类似，不过联合体内的成员共享同一存储区域。且初始化仅能对其中一个成员初始化。
 * 同类型的成员 如果对第一个成员初始化，后面所有成员的值都为第一个初始化的值
 * @Author: Altair
 * @Date: 2020-04-20 10:44:47
 */
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    union Test {
        int8_t a;
        int16_t b;
        int32_t c;
    } u = {.c = 0x11112221};
    // }u = {.c = 0x11112221,.a = 0x11};  // 如果对成员a初始化值，那么 b与c的值都与a相同

    printf("u.a = 0x%.8x\n", u.a);                          // u.a = 0x00000021
    printf("u.b = 0x%.8x\n", u.b);                          // u.b = 0x00002221
    printf("u.c = 0x%.8x\n", u.c);                          // u.c = 0x11112221
    printf("union Test 占:%u个字节\n", sizeof(union Test)); //union Test 占:4个字节
}