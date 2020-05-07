/*
 * @Descripttion: 数组与指针
 * @Author: Altair
 * @Date: 2020-04-27 10:38:15
 */
#include <stdio.h>

int main()
{
    char s[] = "hello world!";
    char *t = s;
    printf("sizeof(s) = %i\n", sizeof(s)); // sizeof(s) = 13 字符个数+一个[\0]
    printf("sizeof(t) = %i\n", sizeof(t)); // sizeof(t) = 8
    // sizeof(数组) 是数组的大小

    printf("&s == s ? %u\n", &s == s); //&s == s ? 1
    printf("&t == t ? %u\n", &t == t); //&t == t ? 0
    
    // s = t;  //会报错 ，计算机会给数组分配存储空间，不会为数组变量s分配空间。数组变量没有分配空间也就不能把它指向其他地方。编译器仅在出现它的地方把它替换成数组的起始地址。
    //数组传递给函数，数组免不了退化为指针。指针变量只会包含数组的地址信息，不会包含数组长度的信息
}