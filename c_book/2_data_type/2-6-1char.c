#include <stdio.h>

/**
 * C语言通过char声明一个字符类型。char类型的对象必须至少能存放基本执行字符集。且为非负整数
 * 
 **/
int main(int argc, const char *argv[])
{
    char a = 98;
    printf("a=%c\n", a); // 输出a=b

    char ch = 'abc';       //某些编辑器会报错
    printf("ch=%c\n", ch); //截取最低位字节'c'给对象ch 输出ch=c

    // int s = 'aa\0cba';          // \0表示字符串的开始 并不会输出aa
    int s = '\0cba';              // \0表示字符串的开始  从最低字节位置取到最高字节位置
    printf("s=%s\n", (char *)&s); //输出s=abc 这里用到了投射与指针的概念

    int str = '\x0\0432';             //相当于 \0  \043<=>#  2
    printf("str=%s\n", (char *)&str); //输出str=2#

    str = '\x43\x42\x41';             //C B A
    printf("str=%s\n", (char *)&str); //输出str=ABC
}