/*
 * @Descripttion: 程序启用独立的进程运行rssgossip.py脚本,子进程一创建就和父进程没关系了。脚本还没执行完，父进程就结束了，所以stories.txt还是空的。
 * 
 * 此时需要waitpid(pid,&pid_status,[options])函数来等待子进程结束以后才返回，
 * 参数说明：
 * pid_t pid： fork时获取到的子进程ID
 * int pid_status：用来保存进程的退出信息，waitpid需要修改pid_status因此必须是个指针。通常可以通过WEXITSTATUS()宏获取子进程退出状态：WEXITSTATUS(pid_status) 如果退出状态不是0则说明有异常。pid_status前八位保存退出状态，其他信息保存在剩余那些位。编译器会把WEXITSTATUS()宏替换为一小段代码。
 * options：选项，详情输入man waitpid查看；0-函数将等待进程结束。
 * 
 * @Author: Altair
 * @Date: 2020-05-07 11:58:03
 */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h> //linux 内核库函数 waitpid()

void error(char *msg)
{
    fprintf(stderr, "%s %s", msg, strerror(errno));
}
int main(int argc, char *argv[])
{
    char *keyword = argv[1];
    char *vars[] = {"RSS_FEED=https://www.fanhaobai.com/atom.xml", NULL};
    FILE *file = fopen("stories.txt", "w");
    if (!file)
    {
        error("Can`t open stories.txt");
    }
    pid_t pid = fork();
    if (pid == -1)
    {
        error("Can`t fork process");
    }

    if (!pid) //仅修改pid = 0 ，即仅修改子进程的标准输出
    {
        if (dup2(fileno(file), 1) == -1) //将标准输出到屏幕指向stories.txt
        {
            error("Can`t redirect Standard Output");
        }
        if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", keyword, NULL, vars) == -1)
        {
            error("Can`t run script");
        }
    }

    /*新增等待rssgossip.py脚本执行完再退出*/
    int pid_status; //用来保存进程信息
    if (waitpid(pid, &pid_status, 0) == -1)
    {
        error("等待子进程时发生错误");
    }
    if(WEXITSTATUS(pid_status))
        puts("运行子进程时发生异常");
    return 0;
}