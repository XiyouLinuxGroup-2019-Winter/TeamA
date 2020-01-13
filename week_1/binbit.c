/*************************************************************************
	> File Name: binbit.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 21时51分54秒
 ************************************************************************/

#include<stdio.h>
char* itobs(int,char*);
void show_bstr(const char*);

int main()
{
    char bin_str[8*sizeof(int)+1];
    int n;
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while(scanf("%d",&n)==1)
    {
        itobs(n,bin_str);
        printf("%d is =",n);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("bye!");
}

char* itobs(int n,char* ps)
{
    int i;
    static int size=8*sizeof(int);
    for(i=size-1;i>=0;i--,n>>=1)
    ps[i]=(01&n)+'0';
    ps[size]='\0';
    return ps;
}
void show_bstr(const char* str)
{
    int i=0;
    while(str[i])
    {
        putchar(str[i]);
        if(++i % 4==0 && str[i]);
    }
}
