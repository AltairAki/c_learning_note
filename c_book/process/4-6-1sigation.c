/*
 * @Descripttion: 
 * @Author: Altair
 * @Date: 2020-05-07 17:09:17
 */
/*
 * @Descripttion: sigaction-捕获信号然后运行自己的代码;
 * 
 * singaction一个函数包装器。它是一个结构体。创建方法如下：
 * struct sigaction action; //创建新动作
 * action.sa_handler = diediedie; //自定义函数来处理信号，这个函数就叫处理器。
 * sigemptyset(&action.sa_mask); //用掩码来过滤sigaction要处理的信号，通常会用一个空的掩码。
 * action.sa_flags = 0; //一些附加标志位，置0即可
 * 
 * 按了Ctrl+c，就会像程序发送中断信号。信号是一条短消息，即一个整型值。当信号到来时，进程必须停止手中一切工作去处理信号。操作系统为什么不直接结束程序，而是在信号表中查找信号？因为这样就可以在进程接收到信号时运行你自己的代码。
 * [ctrl+c对应中断信号-SIGINT，进程运行默认中断处理器调用exit()函数]
 * 
 * 常见信号：
 * SIGINT-进程被中断    
 * SIGQUIT-有人要求停止进程，并把存储器中的内容保存到核心转储文件(core dump file)  
 * SIGFPE-浮点错误     
 * SIGTRAP-调试人员询问进程执行到了哪里
 * SIGSEGV-进程企图访问非法存储器 
 * SIGWINCH-终端窗口的大小发生改变
 * SIGTERM- 有人要求内核终止进程
 * SIGPIPE-进程在像一个没有人读的管道写数据
 * SIGKILL-结束进程，进程不能忽略这个信号
 * 
 * # kill [PID]  默认发送SIGTERM信号
 * # kill -KILL [PID] 杀死进程
 * @Author: Altair
 * @Date: 2020-05-07 17:09:17
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void diediedie(int sig)
{
    puts("自定义的中断信号处理器....\n");
    exit(1);
}

int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;  //windows的信号不是这个 。。。 在linux下可以运行
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int main()
{
    if (catch_signal(SIGINT, diediedie) == -1)
    {
        fprintf(stderr, "无法匹配到处理器");
        exit(2);
    }
    char name[30];
    printf("请输入你的姓名: ");
    fgets(name, 30, stdin);
    printf("你好 %s\n", name);
    return 0;
}