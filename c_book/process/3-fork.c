/*
 * @Descripttion: 用fork()+exec()运行子进程
 * 为了解决exec会终止循环.引入fork概念.
 * fork会克隆当前进程。只有PID（process identifier）和原进程不同。
 * 原进程叫父进程，而新建副本叫子进程。
 * 
 *  pid_t pid = fork();
    fork()会返回一个整型值：为子进程返回0，为父进程返回一个正数。父进程将接收到子进程的进程标识符。什么是pid _t？不同操作系统用不同的整数类型保存进程ID，有的用short，有的用int，操作系统使用哪种类型，pid_t就设为哪个

    fork是写时复制，如果操作系统发现子进程要修改存储器，才会为它真正复制一份。

    另：windows不支持fork()系统调用，windows管理进程的方式与其他系统完全不同。那些用来提高fork()效率的方法在windows上很难实现。但是Cygwin可以实现在windows中调用fork(); 还有一个create-process()的函数，它是加强版的system()。详情见:http://msdn.microsoft.com搜索CreateProcess。
 * 
 * @Author: Altair
 * @Date: 2020-04-22 16:01:29
 */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *feeds[] = {"https://yuanxuxu.com/index.xml",
                     "https://www.fanhaobai.com/atom.xml",
                     "https://coolshell.cn/feed"};
    int times = 3;
    char *phrase = argv[1];
    int i;
    for (i = 0; i < times; i++)
    {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};
        pid_t pid = fork();
        if (pid == -1) //克隆时出错
        {
            fprintf(stderr, "Cannot fork precess: %s\n", strerror(errno));
            return 1;
        }
        if (!pid) // pid为0即当前进程是子进程
        {
            if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1)
            {
                fprintf(stderr, "Cannot run script: %s\n", strerror(errno));
                return 1;
            }
        }
    }
    return 0;
}