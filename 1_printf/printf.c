#include <math.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
    const float M_PI = 3.1415926;
    int len = printf("你好\n");
    printf("长度为：%d\n", len);
    printf("输出字符是:%c,输出浮点数是：%f\n", 'A', M_PI);
    printf("100的十六进制数为：0x%X\n", 100);
    const char *ex = "你好世界";
    printf("你定义的字符是：%s\n", ex);
}