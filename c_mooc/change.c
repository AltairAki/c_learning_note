#include <stdio.h>

int main(int argc, const char *argv[])
{
    printf("请拿出您的银票（元）：");
    int amount = 0, price = 0;
    scanf("%d", &amount);
    printf("请输入商品单价：");
    scanf("%d", &price);

    printf("找您%d元\n", amount - price);
    printf("找您%d元\n", amount);
    return 0;
}