// #include "zenny_utftrans.h"
#include <stdio.h>
#include <uchar.h>

/**
 * C99标准引入了wchar_t类型表示一个多字节字符，wchar_t并不是一个C语言的关键字，而是定义在<stddef.h>头文件中的一个宏类型。wchar_t在不同环境，其长度也可能不一样。当前编译器一般定义为4个字节。
 * 
 * 如果 要 表示 中文、 日文 等 UTF- 8 字符 的 话， 则需 要 使用 字节 数组。 C11 中， 引入 了 新的 头 文件< uchar. h>，UTF-16类型（char16_t）现在一般编译器将其定义为 unsigned short类型，占2个字节；
 * 
 *  以及 UTF-32类型(char32_t) 将其定义为 unsigned int 占4个字节；
 **/
int main(int argc, char *argv[])
{
    char buffer[32];
    wchar_t a = L'你';
    char16_t utf16Char = u'好';
    char16_t utf16Str[] = {a, utf16Char, u'\0'};

    // ZennyUTF16ToUTF8(buffer, utf16Str, NULL);
    // UTF16ToUTF8(buffer, utf16Str, NULL);
    printf("字符串为：%s\n", utf16Str);
    printf("wchar_t宽度为: %u\n", sizeof(utf16Char));
}
