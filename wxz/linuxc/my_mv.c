/*************************************************************************
	> File Name: my_mv.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月07日 星期六 02时55分34秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
int main(int argc,char** argv)
{
    //检查参数的合法性
    if(argc<3)
    {
        printf("my_mv <old file>  <new file>\n");
        exit(0);
    }
    if(rename(argv[1],argv[2])<0)
    {
        perror("rename");
        exit(1);
    }
}
