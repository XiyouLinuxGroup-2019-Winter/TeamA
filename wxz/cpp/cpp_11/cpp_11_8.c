#include <stdio.h>
void reverse(char* p);
int main()
{	
	char a[1000];
	scanf("%s",a);
	reverse(a);
	printf("%s\n",a);
}
void reverse(char* p)
{
	int i,n;
	n=0;
	char temp;
	for(i=0;p[n]!='\0';n++)
		continue;
		n--;
		for(i=0;i<n-i;i++)
		{
			temp=p[i];
			p[i]=p[n-i];
			p[n-i]=temp;
		}
}
