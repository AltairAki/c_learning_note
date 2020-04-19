#include <stdio.h>

int main(int argc)
{
    int a, b;

    scanf("%d,%d", &a, &b); //scanf参数仅能是format 不能有其他字符串

    printf("%d+%d=%d", a, b, a + b);
}