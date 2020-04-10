#include <limits.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 0x10;
    unsigned int b1 = +100U; //完整写法
    unsigned b = +100U;      // int可以省略的
    printf("a的值是：%d\nb的值是：%d\n", a, b);
    printf("a + b = %d\n", a + b);

    unsigned c = -11U;
    unsigned cc = +1U;
    printf("c = 0x%X\n", c); //0xFFFFFFFF
    printf("cc = 0x%X\n", cc);
    printf("a + c = %d\n", a + c); // 这里加法结果溢出，但可将它看做16-1的结果
    printf("c -u输出= %u\n", c);
    a = 0x7FFFFFFF;
    a += 1;
    printf("0xFFFFFFFE减1后十六进制为： 0x%X\n", a);
    printf("0xFFFFFFFE减1后十进制为： %d\n", a); //加法结果溢出，结果为-2147483648

    printf("INT_MIN=%d\n", INT_MIN); //当前c语言实现下int类型的最小值 -2147483648
    printf("INT_MAX=%d\n", INT_MAX); //当前c语言实现下int类型的最大值  2147483647

    printf("UINX_MAX = %u\n", UINT_MAX); //输出当前C语言实现下unsigned int的最大数 4294967295 最小值是0
}