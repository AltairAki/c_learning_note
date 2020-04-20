#include <stdint.h>
#include <stdio.h>

//定义一个名为TRAFFIC_LIGHT的枚举类型
enum TRAFFIC_LIGHT
{
    TRAFFIC_LIGHT_RED,    // 0
    TRAFFIC_LIGHT_YELLOW, // 1
    TRAFFIC_LIGHT_GREEN,  // 2
} g_traffic;              // 定义了一个全局的enum TRAFFIC_LIGHT变量 g_traffic

//定义一个名为LIGHT的枚举类型
static enum LIGHT {
    LIGHT_RED = -2,                  // -2
    LIGHT_ORANGE,                    // -1
    LIGHT_YELLOW = 1,                // 1
    LIGHT_GREEN,                     // 2
    LIGHT_BLUE,                      // 3
    LIGHT_INDIGO = LIGHT_RED + -100, // -102
    LIGHT_PURPLE,                    // -101
    // 定义 了 一个 静态 的 enum LIGHT 变量 s_light
    // 并用 LIGHT_ BLUE 枚举 常量 对其 初始化
} s_light = LIGHT_BLUE;

// 匿名枚举
enum
{
    DICE_ONE = -1, // -1
    DICE_TWO,      // 0
    DICE_THREE,    // 1
    DICE_FOUR,     // 2
    DICE_FIVE,     // 3
    DICE_SIX,      // 4
} g_dic = DICE_TWO;

int main(int argc, const char *argv[])
{
    enum TRAFFIC_LIGHT traffic = TRAFFIC_LIGHT_YELLOW;
    g_traffic = TRAFFIC_LIGHT_GREEN;
    // traffic = 1, g_traffic = 2
    printf("traffic = %d, g_traffic = %d\n", traffic, g_traffic);

    g_dic += 2; //也可以自增，但是不推荐这么做

    int32_t a = g_dic; //枚举变量也能赋值给一个整数变量

    //一个整数变量也可以赋值给一个枚举变量，尽管不推荐这么做
    // 此时 light 并不是一个有效的LIGHT枚举常量值
    enum LIGHT light = a;
    printf("a = %d,light = %d\n", a, light); //a = 2,light = 2
    a += DICE_ONE;
    printf("is a == DICE_FIVE ? %d\n", a == DICE_FIVE);   // is a == DICE_FIVE ? 0
    printf("is a == DICE_THREE ? %d\n", a == DICE_THREE); // is a == DICE_THREE ? 1

    //函数内也可以定义一个枚举类型
    enum SOME_ENUM
    {
        SOME_ENUM1,    // 0
        SOME_ENMU2,    // 1
        SOME_ENUM3,    // 2
    } se = SOME_ENUM1; // 0
    //将( se + 2) 的 结果 类型 显 式 转换 为 enum SOME_ ENUM 类型
    enum SOME_ENUM se2 = (enum SOME_ENUM)(se + 2);
    printf("se2 = %d\n", se2); // se2 = 2
}