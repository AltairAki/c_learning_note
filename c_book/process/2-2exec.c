/*
 * @Descripttion: exec查看网络配置
 * @Author: Altair
 * @Date: 2020-04-22 14:47:19
 */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1) //如果execl()返回-1，就表明它执行失
        if (execlp("ipconfig", "ipconfig", NULL) == -1)
        {
            fprintf(stderr, "Cannot run ipconfig: %s", strerror(errno));
            return 1;
        }
    return 0;
}
