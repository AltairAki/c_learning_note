# Win10 vscode C环境配置
## 1.下载mingw-w64

- [下载页面](http://mingw-w64.org/doku.php/download)

- [百度云链接](https://pan.baidu.com/s/1SBZhpgnpyMm9zc72ACPmvw)
- 提取码：nli2

## 2. 配置环境变量
![image](http://img.gek6.com/FsGkJb-bzekUL2tCuRwQMUH6KcZf)

## 3. 安装 vscode 插件
- C/C++
- Include Autocomplete
- Bracket Pair Colorizer
- Chinese (Simplified) Language Pack for Visual Studio Code


## 4.新建hello_world.c （新建的目录不要有中文，不然编译的时候会报错）

```
#include <stdio.h>

int main(int argc)
{
    char name[20];
    puts("输入男友的名字：");
    scanf("%s", name);
    printf("亲爱的%s,我们分手吧。\n", name);
    return 0;
}
```

## 5.F5调试会生成lauch.json

```
{
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "gcc.exe - 生成和调试活动文件",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "internalConsoleOptions": "neverOpen",
            "MIMode": "gdb",
            "miDebuggerPath": "D:\\software\\mingw64\\bin\\gdb.exe", //换成你自己的环境变量
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "gcc.exe build active file"
        }
    ]
}
```

## 6. 生成task.json
1. Ctrl+shift+p
2. 输入：Tasks:Configure Task 然后按回车
3. 输入：C/C++:gcc.exe build active file 然后按回车

修改task.json
```
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "gcc.exe build active file",
            "command": "gcc",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe",
                "-std=c11" //这行是我新增的
            ],
            "options": {
                "cwd": "D:\\software\\mingw64\\bin" //换成你自己的环境变量
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build"
        }
    ]
}
```
注：因vscode版本不同可能生成的lauch.json和task.json可能会有所差异

此时再次按F5调试，已生成对应exe文件并在终端运行
