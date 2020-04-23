/*
 * @Descripttion: 系统调用  不安全 
 * @Author: Altair
 * @Date: 2020-04-22 11:35:52
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char *now()
{
    time_t t;
    time(&t);
    return asctime(localtime(&t));
}

int main()
{

    char comment[80];
    char cmd[120];
    puts("请输入您要记录的日志内容:"); // ' && ls / && echo ' 不安全
    fgets(comment, 80, stdin);
    sprintf(cmd, "echo '%s %s' >> ./reports.log", comment, now());
    // printf("%s\n",cmd);
    // 请输入您要记录的日志内容: 
    // hello world

    // echo 'hello world
    // Wed Apr 22 12:14:10 2020
    // ' >> ./reports.log

    system(cmd);  //执行cmd的字符串即 echo 'hello world
    // Wed Apr 22 12:14:10 2020
    // ' >> ./reports.log
    
    return 0;
}