/*
 * @Descripttion: 
 * @Author: Altair
 * @Date: 2020-04-22 11:14:36
 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char card_name[3];
    puts("输入牌名：");
    scanf("%2s", card_name);
    int val = 0;
    switch (card_name[0])
    {
    case 'A':
        val = 11;
        break;
    case 'K':
        val = 10;
        break;
    case 'Q':
        val = 10;
        break;
    case 'J':
        val = 10;
        break;
    default:
        val = atoi(card_name); //将字符转为数字
        break;
    }
    
    printf("这张牌的点数为：%i\n",val);
    return 0;
}