#include <stdio.h>

int main(int argc)
{
    char name[20];
    puts("输入男友的名字：");
    scanf("%s", name);
    printf("亲爱的%s,我们分手吧。\n", name);
    return 0;
}