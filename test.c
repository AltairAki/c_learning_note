/*
 * @Descripttion: 
 * @Author: Altair
 * @Date: 2020-04-20 10:31:32
 */
#include <stdbool.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{


    char str[20];  /*定义一个最大长度为19, 末尾是'\0'的字符数组来存储字符串*/
    printf("请输入一个字符串:");
    fgets(str, 7, stdin);  /*从输入流stdin即输入缓冲区中读取7个字符到字符数组str中*/
    printf("%s\n", str);
    return 0;

    // struct test
    // {
    //     int a;
    //     short b;
    //     float c;
    // } t = {.a = 100};
    // printf("%f\n", t.c);

    
    // char a;            // 1
    // short b;           // 2
    // int c;             // 4
    // long int li;       // 4
    // long long int lli; // 16
    // printf("char = %u,short = %u, int = %u, long int = %u \n", sizeof(a), sizeof(b), sizeof(c), sizeof(li));
    // printf("long long int = %u\n", sizeof(lli));

    // float f;        // 4
    // double dou;     // 8
    // long double ld; // 16
    // printf("float = %u,double = %u,long double = %u \n", sizeof(f), sizeof(dou), sizeof(ld));

    // printf("%d\n", 1 > 2);
    // printf("%d\n", true);
    // printf("请拿出您的金额：");
    // int amount;
    // scanf("%d", &amount);
    // int price = 23;
    // printf("找您%d元", amount - price);
    // return 0;
}
