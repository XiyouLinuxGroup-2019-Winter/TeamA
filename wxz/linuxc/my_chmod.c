/*************************************************************************
	> File Name: my_chmod.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月01日 星期日 08时04分51秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc,char **argv)
{
    int mode;//权限
    int mode_u; //所有者的权限
    int mode_g;//所属组的权限
    int mode_o;//其他用户的权限
    char *path;

    //检查参数个数的合法性
    if(argc<3)
    {
        printf("%s <mode num> <target file>\n",argv[0]);
        exit(0);
    }

    //获取命令行参数
    mode=atoi(argv[1]);//将输入的权限
    if(mode > 777 || mode<0)
    {
        printf("mode num error!\n");
        exit(0);
    }
    mode_u=mode/100;
    mode_g=(mode-(mode_u*100))/10;
    mode_o=mode-(mode_u*100)-(mode_g*10);
    mode=(mode_u*8*8)+(mode_g*8)+mode_o;  //转换成十进制
    path=argv[2];       //path指向代更改权限的文件名

    if(chmod(path,mode)==-1)
    {
        perror("chomd error");            //更改权限失败时报错
        exit(1);
    }
}
