/**
 * 结构体
 * 
 * struct 标识符（可省） { 结构体声明列表 }
 * 
 * 结构体声明列表由各个声明（包括静态断言声明）构成。
 **/
#include <stdint.h>
#include <stdio.h>

struct StructTest;

enum MyEnum
{
    MY_Enum1,
    MY_Enum2,
};

struct Mystruct
{
    int32_t a;
    enum MyEnum e;
    double d;
    struct StructTest *pTest;

    // 用一个静态断言作为声明，但不占用此结构体对象的存储空间
    _Static_assert(MY_Enum1 == 0, "NG");
};

struct structTest
{
    int16_t s;

    // 声明了StructTest的一个struct MyStruct 类型成员 m
    struct Mystruct m;

    struct
    {
        int32_t a, b;
        float f;
        ; // 结构 体 声明 列表 末尾 允许 包含 一个 分号， 便于 程序 自动 生成 C 语言 代码
    } i;  // 直接 用此 匿名 结构 体 声明 了 对象 i 作为 StructTest 的 成员
};