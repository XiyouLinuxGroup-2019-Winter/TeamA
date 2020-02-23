/*************************************************************************
	> File Name: j.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 15时44分48秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    int m1,m2,r1,r2,r3;
    char s[1000];
    while(scanf("%d %d",&m1,&m2)!=EOF)
    {
        getchar();
        r1=r2=r3=0;
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='A')
                r1=m1;
            else if(s[i]=='B')
                r2=m2;
            else if(s[i]=='C')
                m1=r3;
            else if(s[i]=='D')
                m2=r3;
            else if(s[i]=='E')
                r3=r1+r2;
            else if(s[i]=='F')
                r3=r1-r2;
        }
        printf("%d,%d\n",m1,m2);
    }
}
