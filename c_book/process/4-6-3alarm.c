/*
 * @Descripttion: 
 * @Author: Altair
 * @Date: 2020-05-07 18:22:46
 */
#include <stdio.h>
#include <signal.h>

int Cnt = 0; //全局计数器变量

void CbSigAlrm(int signo) //SIGALRM信号处理函数
{
    printf("   seconds: %d", ++Cnt); //输出定时提示信息
    printf("\r");

    alarm(1); //又一次启动定时器，实现1秒定时
}
void main()
{
    if (signal(SIGALRM, CbSigAlrm) == SIG_ERR) //安装SIGALRM信号
    {
        perror("signal");
        return;
    }
    setbuf(stdout, NULL); //关闭标准输出的行缓存模式
    alarm(1);             //启动定时器
    while (1)             //进程进入无限循环，仅仅能手动终止
    {
        pause(); //暂停，等待信号
    }
}