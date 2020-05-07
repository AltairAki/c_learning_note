/*
 * @Descripttion: 程序主动发送信号
 * 通常会在自定义的信号处理函数中用raise()就能在接收到低级别信号时引发更高级别的信号。这叫信号升级
 * 
 * @Author: Altair
 * @Date: 2020-05-07 18:01:00
 */

#include <signal.h>

int main(int argc, char *argv[])
{
    raise(SIGTERM);
}