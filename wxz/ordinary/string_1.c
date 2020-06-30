#include <stdio.h>
#include <string.h>
#include <assert.h>

int main()
{
	if((strlen("abc")-strlen("abcdef"))>0)
		printf("HH");
		else
			printf("haha");
}

char* my_strcpy(char* dest,const char* src)
{
	char *ret=dest;
	assert(dest!=NULL);
	assert(src!=NULL);
	/*while(*src)
	{
		*dest=*src;
		dest++;
		src++;
	}
	*dest=*src;*/
	while(*dest++=*src++);
	return ret;
}
int main()
{
	char arr[20]={0};
	const char* p="hello bit";
	my_strcpy(arr,p);
	printf("%s\n",arr);
}

char* my_strcat(char* dest,const char* src)
{
	char* ret=dest;
	assert(dest && src);
	//1.找目的地的'\0'
	while(*dest!='\0')
		dest++:
	//2.拷贝
	while(*dest++=*src++);
		return ret;
}
int main()
{
	char arr[20]="hello ";
	my_strcat(arr,"world");
	printf("%s\n",arr);

}
int main()
{
	char arr[20]="abcdef";
	strcat(arr,arr);
}

int my_strcmp(const char* str1,const char* str2)
{
	assert(str1 && str2);
	while(*str1==*str2)
	{
		if(*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1-*str2;
}
//'\0' -0
//NULL 空指针 -0
//0 -0
//'0' --48
//EOF -end of file (-1)
int main()
{
	int ret=my_strcmp("abw","abq");
	printf("%d\n",ret);
}


int main()
{
	char arr[10]={0};
	strncpy(arr,"hello,word",5);
	printf("%s\n",arr);
}

int main()
{
	char arr[20]="hello \0 xxxxx";
	strncat(arr,"word",3);
	printf("%s\n",arr);
}

int main()
{
	int ret=strncmp("abcdef","abc",5);
	printf("%d\n",ret);
}

//strchr－－字符串找字符
//strstr－－字符串找字符串
int main()
{
	char arr[]="hello world";
	char* ret=strchr(arr,'q');
	if(ret!=NULL)
	printf("%s\n",ret);
}

int main()
{
	char arr[]="abcdefabcdef";
	char* ret=my_strstr(arr,"cde");
	if(ret!=NULL)
		printf("%s\n",ret);
		else
		printf("找不到");
}
