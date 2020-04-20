#include <stdio.h>
/**
 *  enum 标识符 { 枚举符列表 }
 *  枚举标识符  也叫 枚举标签/枚举名
 *  一个枚举符就是一个枚举常量或带有一个常量表达式的枚举常量。
 */

// 整段定义枚举类型的代码称为枚举说明符；
enum LIGHT;
enum TRAFFIC_LIGHT
{
    // TRAFFIC_RED默认值为0，对于之后的所有枚举常量，如果没有常量表达式为它赋值，那么该枚举常量的值为其前一个枚举常量的值加1。
    TRAFFIC_RED,    // 0
    TRAFFIC_GREEN,  // 1
    TRAFFIC_YELLOW, // 2
};
enum LIGHT
{
    //LIGHT_WHITE与LIGHT_RED = -2都是枚举符
    //LIGHT_WHITE与LIGHT_RED 都属于枚举常量
    LIGHT_RED = -2,                  // -2
    LIGHT_WHITE,                     // -1
    LIGHT_ORANGE = 1,                // 1
    LIGHT_INDIGO = LIGHT_RED + -100, // -102
};
