/*************************************************************************
	> File Name: invert4.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 22时52分03秒
 ************************************************************************/

#include<stdio.h>
//使用位操作符来显示二进制
char* itobs(int n,char* ps);
void show_bstr(const char*);
int invert_end(int n,int bit);

int main()
{
    char bin_str[8*sizeof(int)+1];
    int n;
    puts("请输入一个数:");
    while(scanf("%d",&n)==1)
    {
        itobs(n,bin_str);
        printf("%d is\n",n);
        show_bstr(bin_str);
        putchar('\n');
        n=invert_end(n,4);
        printf("反转最后四个字节\n");
        show_bstr(itobs(n,bin_str));
        putchar('\n');
    }
    puts("Bye!");
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

//四位一组显示二进制字符串
void show_bstr(const char* str)
{
    int i=0;
    while(str[i])
    {
        putchar(str[i]);
        if(++i % 4==0 && str[i])
        putchar(' ');
    }
}

int invert_end(int n,int bit)
{
    int mask=0;
    int bitval=1;

    while(bit-->0)
    {
        mask |= bitval;
        bitval<<=1;
    }
    return n^mask;
}
