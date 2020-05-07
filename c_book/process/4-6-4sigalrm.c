/*
 * @Descripttion: 闹钟信号SIGALRM
 * 
 * 不要同时使用sleep()和alarm(),因为sleep也使用了间隔计时器,同时使用会发生冲突。
 * @Author: Altair
 * @Date: 2020-05-07 18:10:24
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void pour_coffee()
{
    puts("冲咖啡");
    exit(1);
}
int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action; //windows的信号不是这个 。。。 在linux下可以运行
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int main()
{
    if (catch_signal(SIGALRM, pour_coffee) == -1)
    {
        fprintf(stderr, "无法匹配到处理器");
        exit(2);
    }
    alarm(3);
    puts("3秒后冲咖啡别忘了");
    while (1)
    {
        pause();
    }
}