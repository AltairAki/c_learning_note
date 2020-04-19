#include <float.h>
#include <stdio.h>

/**
 * float/double 一般保留6位小数
 **/
int main()
{
    float f = 3.5E+3f; //3.5*10^3
    printf("%f\n", f); //3500.000000

    f = 0x3.5P2;       // (3 + 5/16)*2^2
    printf("%f\n", f); //13.250000

    f = .25f;          //0.25
    printf("%f\n", f); //0.250000

    double d = -100.;
    printf("%f\n", d);

    d = 0x30.8P2;      //(3*16+8/16)2^2
    printf("%f\n", d); //194.000000

    // long double g = -0x3.5P0L; // 3+5/16=3.3125
    // printf("%Lf\n", g);

    // 定义 一个 long double 类型 的 对象 g
    // long double g = -0x3.5P0L; //win10下输出0.000000
    double g = -0x3.5P0;
    // g 的 值 为- 0x3. 5 * 1 = -3.3125
    printf("g = %Lf\n", g); // -3.3125

    g = 0x18.F8P2L * 2E3;                              // (24+15/16+8/16^2) * 2^2 * 2*10^3  (15/16=0.9375; 8/256=0.03125;)
    printf("%f\n", g);                                 //199750.000000
    printf("double size is : %u bytes \n", sizeof(g)); // 8 bytes

    printf("%g\n", DBL_MAX);   //1.79769e+308
    printf("%Lg\n", LDBL_MIN); //3.17291e-317 win10 \mingw64
    printf("%Lg\n", LDBL_MAX); //3.17291e-317 win10 \mingw64

    float ff = 1.000000F;
    double dd = 2.000000;
    long double ld = 2.000000L;
    printf("ff的长度为：%d,dd的长度为：%d,ld的长度为：%d", sizeof(ff), sizeof(dd), sizeof(ld));
    //ff的长度为：4,dd的长度为：8,ld的长度为：16
}