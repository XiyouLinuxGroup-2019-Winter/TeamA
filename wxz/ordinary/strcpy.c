#include <stdio.h>
#include <string.h>
#include <assert.h>
char * my_strcpy(char*dest,const char *src)
{
	char *ret=dest;
	assert(dest!=NULL);
	assert(src!=NULL);
	while(*dest++=*src++);
	return ret;
}
int my_strlen(const char*str)
{
	int count=0;
	assert(str!=NULL);
	while(*str++!='\0')
	{
		count++;
	}
	return count;
}
int main()
{
	char arr1[20]={0};
	char arr2[20]="BIT";
	char*p="abcdef";
	my_strcpy(arr1,arr2);
	printf("%s\n",arr1);
	printf("%d\n",my_strlen(arr1));
}

/*int main()
{
	const int num=10;
	int n=0;
	const int *p=&num;
	int *const ppa=&num;
	//const放在*的左边，修饰的是*ｐ，意思是指针指向的内容不能被改变
	/p=20;
	p=&n;
	printf("%d\n",num);
	
}*/
/*
int main()
{
	int *p=NULL;
	if(p!=NULL)
	*p=20;
	
}
char *test()
{
	char arr[]="abcdef";
	return arr;
}
int main()
{
	char *str=test();
	printf("%s\n",str);
}*/
