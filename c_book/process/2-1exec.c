/*
 * @Descripttion: exec()和system()一样也是系统调用
 * 明确地告诉操作系统你想运行哪个程序,这就是exec()函数的用处
 * 
 * exec()函数替换当前进程【这个脚本即：2-1exec.c编译后的可执行文件运行时的进程】
 * 
 * 列表（参数）函数：execl()、execlp()、execle()
 * 数组（参数）函数：execv()、execvp()、execve()
 * 其中：l-参数列表 v-参数数组/向量 p-根据PATH查找 e-环境变量
 * 
 * 如果exec()调用成功，当前程序就会停止运行。一旦程序运行了exec()以后的代码，就说明出了问题。
 * 
 * 如果在调用程序时发生错误，当前进程会继续运行。这点很有用，因为就算第二个进程启动失败，还是能够从错误中恢复过来，并向用户报告错误信息.
 * 
 * @Author: Altair
 * @Date: 2020-04-22 12:40:22
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main(int argc, char *argv[])
{
    char *my_env[] = {"Juice=peach and apple", NULL};
    execle("C:/code/learnning/c_learning_note/c_book/jinc/2-1dinner.exe", "C:/code/learnning/c_learning_note/c_book/jinc/2-1dinner.exe", "4", NULL, my_env);
    // puts("哥们，dinner 程序肯定发生了什么问题"); // execle执行成功，不会执行这行代码
    printf("%i\n",errno);  // 2
    /**
     *  errno变量是定义在errno.h中的全局变量，和它定义在一起的还有很多标准错误码，其中：
        EPERM=1 不允许操作
        ENOENT=2 没有该文件或目录
        ESRCH=3 没有该进程
        EMULLET=81 发型很难看  这个值在任何系统上都不存在。
    **/
    puts(strerror(errno));  //strerror()将错误码转换为一条消息 No such file or directory

    return 0;
}