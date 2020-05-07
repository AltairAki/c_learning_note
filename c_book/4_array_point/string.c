/*
 * @Descripttion: 字符串存在数组中
 * @Author: Altair
 * @Date: 2020-04-26 19:57:30
 */
#include <stdio.h>
void fortune_cookie(char msg[])
{
    printf("message reads: %s\n", msg);                 // message reads: this is string hello world
    printf("message occupies %i bytes\n", sizeof(msg)); // message occupies 8 bytes
    /*
        为什么sizeof(msg)小于整个字符串的长度，msg是什么？
        quote就是数组起始地址，所以传给函数的是指针。msg指向传进来的消息。sizeof(msg)就是指针变量的大小。指针在32位操作系统占4字节，在64位操作系统占8字节。
    */
}

int main()
{
    char quote[] = "thissads is string";
    printf("The quote 字符串保存在：%p\n", quote);
    fortune_cookie(quote);
}