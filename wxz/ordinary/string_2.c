#include <stdio.h>
char* my_strstr(const char* s1,const char* s2);
int main()
{
	char arr[]="abbbcdef";
	char* ret=my_strstr(arr,"cde");
	if(ret!=NULL)
	printf("%s\n",ret);
	else
		printf("找不到\n");
}
char* my_strstr(const char* s1,const char* s2)
{
	const char* p1=s1;
	const char* p2=s2;
	const char* start=p1;

	if(*s2=='\0')
	return s1;
	while(*start)//没有遇到'\0'
	{
		p1=start;//起始位置
		p2=s2;//p2回到开头
		while(*p1 && *p2 && *p1==*p2)//防止越界访问假如最后两个都是'\0'会无限往后走
		{
			p1++;
			p2++;
		}
		if(*p2=='\0')
			return (char*)start;//已经找到了
		start++;//记录的是相等的时候的起始位置
	}
	return NULL;
}
//"abcdef"里找"cde"
//   s1         s2
//"abbbcdef"里找"bbc"
//匹配失败时回到起始匹配的下一个位置(上一个指针的位置)

//"ABCDEF"
//"CDE"

//"ABBBCDEF"
//"BBC"
//一开始start和p1都指向A
//p2指向B

//优化：当已经找不到的时候可以提前结束
//KMP算法优化---vaues数组
