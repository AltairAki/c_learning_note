/*
 * @Descripttion: 
 * 使用指针的两个原因：
 * 1. 让函数共享存储器；2. 避免副本，函数调用时，可以只传递一个指针，而不用传递整份数据；
 * @Author: Altair
 * @Date: 2020-04-26 19:32:48
 */

void get_now_position(int *latitude, int *longitude)
{
    *latitude = *latitude - 1;
    *longitude = *longitude + 1;
}

int main()
{
    int latitude = 32;
    int longtitude = -64;
    get_now_position(&latitude, &longtitude);
    printf("现在的位置：%d,%d\n", latitude, longtitude);
    return 0;
}

