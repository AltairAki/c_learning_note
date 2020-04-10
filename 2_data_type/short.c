#include <limits.h>
#include <stdio.h>

int main(int args, char *argv[])
{
    short a = 100, b = 200;
    printf("a - b = %d\n", a - b); //-100

    unsigned short c = 100;
    c -= 200;

    //将 一个 带 符号 整数（ 补码 形式） 转为 无符号 整数
    printf("c=%hu\n", c); // 输出65436 相当于65536-100

    printf("SHRT_MIN=%d\n", SHRT_MIN); //输出当前c语言实现下short类型的最小值  -32768
    printf("SHRT_MSX=%d\n", SHRT_MAX); //输出当前C语言实现下short类型的最大值   32767

    //输出当前c语言实现下unsigned short类型的最大值
    // 由于unsigned short类型的最小值已被标准定义为0
    printf("USHRT_MAX=%d\n", USHRT_MAX); // 65535
}