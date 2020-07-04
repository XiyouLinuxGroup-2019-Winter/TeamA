/*************************************************************************
	> File Name: bignum.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 23时34分45秒
 ************************************************************************/


#include <stdio.h>
#include <string.h>
int main()
{
    char str1[256]={0};
    char str2[256]={0};

    scanf("%s",str1);
    scanf("%s",str2);
    
    int lena=strlen(str1);
    int lenb=strlen(str2);

    int a[256]={0};
    int b[256]={0};
    int c[256]={0};

    for(int i=0;i<lena;i++)
        a[i]=str1[lena-i-1]-'0';

    for(int i=0;i<lenb;i++)
        b[i]=str2[lenb-1-i]-'0';

    int x=0;
    for(int i=0;i<lena || i<lenb;i++)
    {
        c[i]=(a[i]+b[i]+x)%10;
        x=(a[i]+b[i]+x)/10;
    }
    int lenc=sizeof(c)/sizeof(int);
    while((c[lenc-1]==0) && (lenc>0))
        lenc--;

    for(int i=lenc-1;i>=0;i--)
        printf("%d",c[i]);
    printf("\n");
}
/*#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,a[2000]={0},b[2000]={0},max,len1,len2,t;
    char str1[2000],str2[2000];
    while(fgets(str1,2000,stdin),fgets(str2,2000,stdin))
    {
        t=0;
        int c[2000]={0};//每次c[200]中存入数后，进行下一次计算前都要清零
        //取两数组中最长的那个
        len1=strlen(str1);
        len2=strlen(str2);
        max=len1;
        if(len1>max)
            max=len2;
        //将字符数组逆序存入整形数组
        for(i=len1-1;i>=0;i--)
            a[t++]=str1[i]-'0';
        t=0;
        for(i=len2-1;i>=0;i--)
            b[t++]=str2[i]-'0';
        t=0;
        for(i=0;i<max;i++)
        {
            c[i]=a[i]+b[i]+c[i];
            if(c[i]>=10)
            {
                c[i]-=10;
                c[i+1]++;//解决进位
            }
        }
        if(c[max]!=0)
            printf("%d",c[max]);
        for(i=max-1;i>=0;i--)
            printf("%d",c[i]);
        printf("\n");
    }
}*/

/*#include<stdio.h>
#include <string.h>

void reverse(char* str);//倒置
void addbig(char* str1,char* str2,char* result);//大整数加法
void redubig(char* str1,char* str2,char* result);//大整数减法
int main()
{
    int n;
    char str1[100]=[0],str2[100]={0};
    char result[100]={0};
    char reduce[100]={0};
    char begin[100][100]={0};
    char end[100][100]={0};

    int k,j;
    int total;

    scanf("%d",&n);
    total=n;
    getchar();
    k=0;
    while(n--&&k<total)
    {
        gets(str1);
        gets(str2);
        reverse(str1);
        reverse(str2);
        addbig(str1,str2,result);
        strcpy(begin[k],result);
        redubig(str1,str2,reduce);
        strcpy(end[k++],reduce);
    }
    for(k=0)
}*/
