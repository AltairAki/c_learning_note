#include <stdio.h>

static struct MyPoint
{
    float x, y;
} g_point;
/*
如果一个结构体类型声明的对象具有静态存储周期（将在11.3节中介绍）或线程存储周期（将在11.7节中介绍）—— 比如在文件作用域声明的对象g_point，那么该结构体对象的所有成员在执行main函数前被系统默认初始化为0。
*/

int main(int argc, const char *argv[])
{
    struct MyPoint point;
    point.x = 1.00;
    point.y = 1.00;

    // g_point.x = 0.000000,g_point.y = 0.000000
    // Point.x = 1.000000,Point.y = 1.000000
    printf("g_point.x = %f,g_point.y = %f\n", g_point.x, g_point.y);
    printf("point.x = %f,point.y = %f\n", point.x, point.y);

    struct MyPoint *pPoint = &point;
    // 访问一个指向结构体指针的对象，使用->操作符
    pPoint->x = 1.1f;
    printf("point.x = %f\n", point.x); // 1.100000

    struct MyPoint point2 = {100.f, 50.f};
    printf("point2.x = %f,point2.y = %f\n", point2.x, point2.y);
    //point2.x = 100.000000,point2.y = 50.000000

    // 结构 体 对象 允许 直接 用 等号 赋值， 此时 C 语言 实现 会 直接 将此 赋值 操作 拆分 为
    // 依次 用“=” 右 操 作数 的 结构 体 成员 对象 的 值 赋值 给= 左 操作 数 结构 体 成员 对象 的 值，
    // 不过 各个 成员 对象 的 赋值 执行 次序 是由 实现 定义 的，
    // 未必 严格 按照 成员 对象 在 结构 体中 定义 的 顺序 进行
    point = point2;
    printf("point.x = %f,point.y = %f\n", point.x, point.y);
    //point.x = 100.000000,point.y = 50.000000

    struct MyRectangle
    {
        enum
        {
            COLOR_RED,
            COLOR_GREEN,
            COLOR_YELLOW,
        } color;
        struct MyPoint position;
        struct
        {
            float width, height;
        } size;
    } rect = {COLOR_RED, 10.0f, 20.0f, 90.0f, 35.f},
      // 对 其 成员 size 对象 中的 所有 成员 直接 出 初始化 为零
        rect2 = {COLOR_GREEN, {30.F}, {}};

    printf("rect.clolor = %d,rect, rect.position.x = %f,rect.position.y = %f,rect.size.width = %f,rect.size.height = %f\n",
           rect.color, rect.position.x, rect.position.y, rect.size.width, rect.size.height);
    printf("rect2.clolor = %d, rect2.position.x = %f,rect2.position.y = %f,rect2.size.width = %f,rect2.size.height = %f\n",
           rect2.color, rect2.position.x, rect2.position.y, rect2.size.width, rect2.size.height);

    struct MyRectangle rect3 = {
        .color = COLOR_YELLOW,
        .position.x = 10.f,
        .position.y = 11.1f,
        {.height = 11.0f},
    };
    printf("%f", rect3.size.width); // 未赋值初始值为0.000000
}
