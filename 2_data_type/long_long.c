#include <limits.h>
#include <stdio.h>

/**
 * 无论32位系统还是64位系统long long 均占8个字节(64位)
 * */
int main(int argc, char *argv[])
{
    long long a = 100;

    int bb = 0x100000000;     //这里已超出int范围故输出为0
    printf("bb = %ld\n", bb); // 0

    //测试环境为mingW64
    //编译器不加LL也可以
    //但倘若不加后缀 LL，在某些编译器上会出现警告，在运行时也可能出现数据被截断的情况
    long long b1 = 0x100000000; //2^32 = 4294967296
    printf("b1=%lld\n", b1);
    long long b2 = 0x100000000LL; //2^32 = 4294967296
    printf("b2=%lld\n", b2);
    printf("a+b=%lld\n", a + b2); //100+2^32=4294967396

    unsigned long long c = 100UL;

    // 声明 一个 unsigned long long 类型 对象 d
    // 1000000 表示 一个 int 类型 的 整数 字面 量
    // 但 由于 unsigned long long 的 精度 至少 不小于 int 类型 的 精度，
    // 所以 int 可以 隐式 转为 unsigned long long 类型
    unsigned long long d = 1000000;

    printf("c*d=%llu\n", c * d); //100*1000000=100000000

    printf("LLONG_MIN = %lld\n", LLONG_MIN); //-9223372036854775808 = -2^63
    printf("LLONG_MAX = %lld\n", LLONG_MAX); //9223372036854775807 2^63-1

    printf(" ULLONG_MAX = %llu\n", ULLONG_MAX); //18446744073709551615 2^64-1
}