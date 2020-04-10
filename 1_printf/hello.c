#include <stdio.h>

int main()
{
    char ex[20];
    puts("输入男友的名字：");
    scanf("%s", ex);
    printf("亲爱的%s,我们分手吧。\n", ex);
    return 0;
}