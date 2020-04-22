/*
 * @Descripttion: 
 * 为了解决exec会终止循环.引入fork概念.
 * fork会克隆当前进程。只有PID（process identifier）和原进程不同。
 * 原进程叫父进程，而新建副本叫子进程。
 * 
 *  pid_t pid = fork();
    fork()会返回一个整型值：为子进程返回0，为父进程返回一个正数。父进程将接收到子进程的进程标识符。什么是pid _t？不同操作系统用不同的整数类型保存进程ID，有的用short，有的用int，操作系统使用哪种类型，pid_t就设为哪个
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
        if (!pid) // pid为0
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