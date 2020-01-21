/*************************************************************************
	> File Name: 元音字母.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 11时46分16秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
    int n;
    char a[200];
    int b[5];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        mZcanf("%s",a);
        int len=strlen(a);
        int i=0;
        for(i=0;i<5;i++)
        b[i]=0;
        for(i=0;i<len;i++)
        {
            if(a[i]=='a')
                b[0]++;
            if(a[i]=='e')
                b[1]++;
            if(a[i]=='i')
                b[2]++;
            if(a[i]=='o')
                b[3]++;
            if(a[i]=='u')
                b[4]++;
        }
       printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",b[0],b[1],b[2],b[3],b[4]);
    if(n!=0)
        printf("\n");
    }
       
}
