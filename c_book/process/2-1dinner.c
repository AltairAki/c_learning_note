/*
 * @Descripttion: 
 * @Author: Altair
 * @Date: 2020-04-22 14:26:18
 */
#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
int main(int argc,char *argv[])
{
    printf("Diners: %s\n", argv[1]);
    printf("Juice: %s\n", getenv("Juice")); //你可以使用stdlib.h中的getenv()读取环境变量。
    return 0;
}