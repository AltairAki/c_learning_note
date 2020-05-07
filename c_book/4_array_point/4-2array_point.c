/*
 * @Descripttion: 下标操作符
 * @Author: Altair
 * @Date: 2020-04-29 15:44:53
 */

#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 1000};
    printf("%d\n", 3 [arr]); //arr[3] == *(arr+3) == *(3+arr) == 3 [arr]
}