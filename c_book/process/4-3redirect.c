/*
 * @Descripttion: 通过dup2([fileno(FILE *file)],[0,1,2])重定向
 * @Author: Altair
 * @Date: 2020-05-06 13:51:06
 */
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

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
        if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", keyword, NULL,vars) == -1)
        {
            error("Can`t run script");
        }
    }
    return 0;
}