/*************************************************************************
	> File Name: cpp_15_2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 01时30分54秒
 ************************************************************************/

#include<stdio.h>
int transite(char* pf);
int main(int argc,char** argv)
{
    if(argc<3)
    printf("程序错误\n");
    
    int n1=0;
    int n2=0;

    n1=transite(argv[1]);
    n2=transite(argv[2]);

    int a1=~n1;
    int a2=~n2;

    int and=n1&n2;

    int or=n1|n2;

    int xor=n1^n2;

    printf("%s %s %s %s",a1,a2,and,or,xor);
}
int transite(char* pf)
{
    int n=0;
    for(int i=0;pf[i];i++)
    {
        n<<=1;
        n |=(pf[i]-'0');
    }
    return n;
}
