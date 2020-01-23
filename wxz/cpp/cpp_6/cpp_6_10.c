#include <stdio.h>
#include <string.h>
int main()
{
        char a[8];
        int i,len;
        for(i=0;i<8;i++)
        scanf("%d",&a[i]);
        len=strlen(a)-1;
        for(i=len;i>=0;i--)
        printf("%d ",a[i]);
	printf("\n");
}

