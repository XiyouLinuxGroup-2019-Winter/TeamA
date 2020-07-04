#include <stdio.h>
#include <string.h>
void print_list(char** dest,int n);
void print_ascll(char** dest,int n);
void print_length(char** dest,int n);
void print_wordlength(char** dest,int n);
int main()
{
	int n,m;
	char a[100][100];
	char *p[10];
	while(1)
	{
		n=0;
		if(gets(a)==NULL)
			break;
			p[n]=a[n];
			n++;
	}
	while(n<10)
	{
	printf("请输入要选择的选项\n");
	printf("1).输出初始字符串列表\n");
	printf("2).按ASCLL顺序输出字符串\n");
	printf("3).按长度递增顺序输出字符串\n");
	printf("4).按字符串第一个单词的长度输出字符串\n");
	printf("5).退出\n");
	do
	{
		scanf("%d",&m);
		switch(m)
		{
			case '1':
			print_list(p,n);
			break;
			case '2':
			print_ascll(p,n);
			break;
			case '3':
			print_length(p,n);
			break;
			case '4':
			print_wordlength(p,n);
			break;
			default:
			printf("quit\n");
		}
	}while(m!=5);
	}
}
void print_list(char** dest,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%s ",p[i]);
}
void print_ascll(char** dest,int n)
{
	int i,j;
	char* temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(strcmp(p[j],p[j+1])>0)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	printf("%s ",p[i]);
}
void print_length(char** dest,int n)
{
	char* temp;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(strlen(p[j])>strlen(p[j+1]))
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%s ",p[i]);
}
/*void print_wordlength(char** dest,int n)
{
	
}*/
