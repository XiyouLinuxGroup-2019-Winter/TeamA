#include <stdio.h>
int is_within(char ch,char* p);
int main()
{
	char a[100]="anauwskalqw";
	//scanf("%s",a);
	//fgets(a,100,stdin);
	char ch='a';
	//ch=getchar();
	int i=is_within(ch,a);
	printf("%d\n",i);
}
int is_within(char ch,char* p)
{
	while(*p++!='\0')
	{	
		if(*p==ch)	
		return 1;
		return 0;
	}
}
