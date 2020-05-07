/*
 * @Descripttion: 进程通信
 * 可以通过进程间通信，控制运行中的进程，向进程发送数据或读取它的输出。进程可以合力完成某件工作。
 * 本例向你展示如何让程序与系统其他程序通信，从而提升性能。 
 * 
 * 输入输出重定向：
 *      ">"可以把标准输出重定向到文件 - (如 python ./rssgossip.py [关键词] > stories.txt)
 *      标准输入:stdin | 标准输出:stdout(可以用 > 把标准输出重定向到文件) | 标准错误:stderr
 * 标准输出是三大默认数据流之一，顾名思义，数据就是从一个进程流出，流入另一个进程。其他的文件连接和网络连接也属于数据流。重定向把原来标准输出会把数据发送到屏幕，现在可以让它把数据发送到文件。
 * 
 * 文件描述符：
 * 进程用文件描述符表示数据流，文件描述符就一个数字：0-标准输入[数据流-键盘]，1-标准输出[数据流-屏幕]，2-标准错误[数据流-屏幕]，3-进程也可能打开其他形式的数据流[如：数据库连接]。其中前三项万年不变；
 * 
 * 重定向标准错误 ./myprog > output.txt 2> errors.log
 *               ./myprog 2>&1  //把标准错误与标准输出重定向到同一个地方
 * @Author: Altair
 * @Date: 2020-04-23 12:02:06
 */
#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *my_file = fopen("guitar.txt", "r");
    int descriptor = fileno(my_file); // 失败时不返回-1的函数很少，fileno就是其中之一
    printf("file_no = %d\n", descriptor); //输出3

    FILE *my_file2 = fopen("guitar2.txt", "r");
    int descriptor2 = fileno(my_file2);
    printf("file_no_2 = %d\n", descriptor2); //输出4

    /**
     *dup2复制数据流,每次打开文件都会使用描述符表新的一项。可以通过dup2修改某个已经注册过的数据流，比如让数据流3重新指向其他数据流。 
     虽然guitar2.txt只有一个，与它相连的数据流也只有一条，但数据流(FILE*)同时注册在了文件描述符3和4中。
     **/
    dup2(4,3);
}