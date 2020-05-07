/*
 * @Descripttion: 程序一次搜索多个RSS源
 * 
 *  RSS Gossip脚本下载地址：
    https://github.com/dogriffiths/rssgossip/zipball/master

    如果你没有安装过Python，可以从这里下载：
    http://www.python.org/  

 * @Author: Altair
 * @Date: 2020-04-22 16:06:19
 */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
// argc 一般存放执行当前程序时输入的命令字符串个数；argv[]一般存放指向各个输入字符串的指针
// 假设有已gcc编译过的可执行文件test,在控制台输入 test arg1 arg2,再按回车，那么main函数的第一个参数argc为3，test就是argv[0],argv对应的实参内容为：{"test","arg1","arg2"}
int main(int argc, char *argv[])
{
    char *feeds[] = {
                    "https://yuanxuxu.com/index.xml",
                    "http://www.cnn.com/rss/celebs.xml",
                     "http://www.rollingstone.com/rock.xml",
                     "http://eonline.com/gossip.xml"};
    int times = 4;
    char *phrase = argv[1];
    int i;
    for (i = 0; i < times; i++)
    {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};
        if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1)
        {
            fprintf(stderr, "Can't run script: %s\n", strerror(errno));
            return 1;
        }
    }
    return 0;
}