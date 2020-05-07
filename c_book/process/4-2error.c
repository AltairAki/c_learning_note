/*
 * @Descripttion: 
 * @Author: Altair
 * @Date: 2020-05-06 13:25:50
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
int main(int argc, char *argv[])
{
    pid_t pid = fork(); // unistd.h  windows 不支持fork哦
    if(pid == -1){
        error("无法克隆进程");
    }
}