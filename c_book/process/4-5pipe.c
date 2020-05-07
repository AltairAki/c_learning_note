/*
 * @Descripttion: 
 * python rssgossip.py -u 'key' | grep 'http'
 * 管道两侧的命令是父子关系，grep是rssgossip.py脚本的父进程。
 * 1.命令行创建父进程。2.父进程在子进程中克隆了rssgossip.py脚本。3.父进程用管道把子进程的输出连接到自己的输入。4.父进程运行了grep命令。
 * 
 * C语言通过pipe()函数建立管道，连接子进程标准输出与父进程标准输入。每当打开数据流时，它都会加入描述符表。pipe()创建两条相连的数据流，并把它们加入描述符表中，然后只要你往其中一条数据流中写数据，就可以从另一条数据流读取。
 * 
 * int fd[2]; //描述符将被保存在fd数组 fd[1]写管道，fd[0]读管道。
 * if(pipe(fd) == -1)
 * {
 *      error("管道创建失败");
 * }
 * 
 * 注：管道只能单向通信。不过可以创建两个管道，一个从父进程连到子进程，另一个从子进程连到父进程来实现双向通信。
 * 
 * 总结：1.pipe创建一个管道两个描述符。2.一个描述符是管道的读取端另一个是写入端。3.可以把标准输入和标准输出重 定向到管道。4.父子进程各自使用管道的一端。 
 * @Author: Altair
 * @Date: 2020-05-07 14:29:20
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void open_url(char *url)
{
    char launch[255];
    sprintf(launch, "cmd /c start %s", url); //windows
    system(launch);
    sprintf(launch, "x-www-browser '%s'", url); //linux
    system(launch);
    sprintf(launch, "open '%s'", url); //mac
    system(launch);
}
void error(char *msg)
{
    fprintf(stderr, "%s %s", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    char *keyword = argv[1];
    char *vars[] = {"RSS_FEED=https://www.fanhaobai.com/atom.xml", NULL};
    int fd[2];
    if (pipe(fd) == -1)
    {
        error("创建管道失败");
    }

    pid_t pid = fork();
    if (pid == -1)
        error("创建子进程失败");
    if (!pid) //子进程
    {
        if (dup2(fd[1], 1) == -1) //把标准输出设为管道的写入端。
        {
            error("Can`t redirect std output to fd[1]");
        }
        close(fd[0]); //子进程不需要读取管道
        if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", keyword, NULL, vars) == -1)
        {
            error("执行脚本失败");
        }
    }

    if (dup2(fd[0], 0) == -1)
    {
        error("Can`t redirect Standard input to fd[0]");
    }
    close(fd[1]); //关闭管道的写入端，父进程不需要向管道写数据

    char line[255];

    //子进程结束时，管道会关闭。fgets()将收到EOF(End OfFile,文件结束符)，于是fgets()函数返回0循环结束。
    while (fgets(line, 255, stdin)) //将从标准输入读取数据，因为管道连接到标准输入 也可以用fd[0]
    {
        printf("找到：%s\n", line);
    }
    return 0;
}
