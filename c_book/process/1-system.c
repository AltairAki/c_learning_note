/*
操作系统内核主管：1-进程；2-存储器；3-硬件

进程：只有当内核把程序加载到存储器时程序才能运行。内核创建进程，并确保它们得到了所需资源。内核同 时也会留意那些变得贪得无厌或者已经崩溃的进程。 

存储器：计算机所能提供的存储器资源是有限的，因此内核必须小心翼翼地分配每个进程所能使用的存储器大 小。内核还能把部分存储器交换到磁盘从而增加虚拟存储器空间。

硬件：内核利用设备驱动与连接到计算机上的设备交互。你的程序在不了解键盘、屏幕和图形处理器的情况下 就能使用它们，因为内核会代表你与它们交涉。 系统调用是程序用来与内核对话的函数。

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