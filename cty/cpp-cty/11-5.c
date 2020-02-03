#include <stdio.h>
#define LENGTH 20
char* search(char* st,char ch);
char* s_gets(char* st,int n);
int main(void)
{
	char string[LENGTH];
	char a;
	char* p_a;
	printf("请输入字符串(小于 %d 字符)\n",LENGTH);
	if (s_gets(string,LENGTH))
	{
		printf("字符串为:");
		puts(string);
		printf("\n请输入字符(空行来结束)\n");
		while ((a=getchar())!='\n')
		{
			p_a=search(string,a);
			if(p_a)
				printf("其余的字符为:\"%s\"",p_a);
			else
				printf("没有这样的字符");
			printf("\n请输入另一个字符(空行来结束)\n");
			while(getchar()!='\n')
				continue;
		}		
	}
	else
		printf("error\n");
	printf("bye\n");
	return 0;
}

char* s_gets(char* st,int n)
{
	char* ret_val;
	ret_val=fgets(st,n,stdin);
	if (ret_val)
	{
		while(*st != '\n' && *st != '\0')
			st++;
		if(*st == '\n')
			*st='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return ret_val;
}

char* search(char* st,char ch)
{
	char* target;
	while(*st != '\0' && *st != ch)
		st++;
	if (*st == ch)
		target = st;
	else
		target = NULL;
	return target;
}
