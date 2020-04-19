#include <stdbool.h>
#include <stdio.h>
/**
 * 关系操作符与移位操作符
 * 
 * 总结：左移都补0；右移带符号补符号位，无符号补0；
 **/
int main(int argc, const char *argv[])
{
    /*关系操作符*/
    int i = 0, j = 0;
    bool b1 = 2 > 1 && i++ == 2;
    printf("b1=%d\n", b1);
    printf("i=%d\n", i);

    bool b2 = 2 > 1 || j++ == 2;
    printf("b2=%d\n", b2);
    printf("j=%d\n", j);

    /*
        移位操作符
        1.算术左移与逻辑左移操作基本是相同的，要左移N位，那么先将整数的每个比特向左移动N位，然后空出的低N位填零。
        2.1 逻辑右移的操作步序是：先将整数的每一个比特向右移动N位，然后高N位用零来填补。
        2.2 算数右移的操作步序是：移出N位之后，高N位不是用零来填充，而是根据原始整数的最高位，如果原始整数的最高位为1，那么移位后的高N位用1来填充；如果是0，则用0来填充。
    */

    int a = 1;      //00000000 00000000 00000000 000000001
    unsigned b = 1; //00000000 00000000 00000000 000000001
    printf("b的字节长度为：%d\n", sizeof(b));
    // 相当于a = a<<2,将整数左移两位  00000000 00000000 00000000 000000001 =》 .. .. .. . 0100
    a <<= 2;
    printf("a = %d\n", a); //输出 a=4
    // .. .. .. . 1000
    b <<= 3;
    printf("b = %d\n", b); //输出 b=8

    int c = -1; //11111111 11111111 11111111 1111111
    printf("%x\n", c);
    c <<= 31;          //100000000 00000000 00000000 00000000
    printf("%x\n", c); // 80000000
    printf("%d\n", c); // -2147483648

    //当前a的值用十六进制表示为：0xfffffff6
    a = -10; // 11111111 11111111 11111111 11110110
    b = 0xfffffff6;
    //相当于a=a>>30，由于a是带符号整数，所以这里做的是算术右移
    a >>= 30; //11111111 11111111 11111111 11111111
    //相当于b=b>>30，由于b是无符号整数，所以这里做的是逻辑右移
    b >>= 30;
    //输出：a=-1,b=3
    printf("a=%d,b=%d\n", a, b);

    //圆括号提升优先级
    int *p = (int[]){1, 2};
    printf("*p = %d\n", *p); // *p = 1
    (*(p + 1))++;
    printf("p[1] = %d\n", p[1]); // 3
}