#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <assert.h>
int main()
{
	//char arr[]="192.169.0.1";//点分十进制
	char arr[]="zpw@bitedu.tech";
	char tmp[20];

	char* sep="@.";
	char* ret=NULL;
	strcpy(tmp,arr);

	ret=strtok(tmp,sep);
	printf("%s\n",ret);
	ret=strtok(NULL,sep);
	printf("%s\n",ret);
	ret=strtok(NULL,sep);
	printf("%s\n",ret);
	
	for(ret=strtok(tmp,sep);ret!=NULL;ret=strtok(NULL,sep))
		printf("%s\n",ret);
		
}

int main()
{
	printf("%s\n",strerror(errno));
	printf("%s\n",strerror(1));
	printf("%s\n",strerror(2));
	//把错误码转化为错误信息
}

int main()
{
	//打开文件
	FILE* pf=fopen("test.txt","r");
	if(pf==NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	//读文件
	//关闭文件
	fclose(pf);
	pf=NULL;
}

int main()
{
	printf("%d\n",isspace('a'));
	printf("%d\n",isdigit('1'));
}

void* my_memcpy(void* dest,const void* src,size_t count)
{
	assert(dest && src);
	void* ret=dest;
	//count个字节，循环count次
	while(count--)
	{
		*(char*)dest=*(char*)src;

		dest=(char*)dest+1;
		src=(char*)src+1;

		//((char*)dest)++;//++(char*)dest
		//((char*)src)++;//++(char*)src
	}
	//return ret;
}
int main()
{
	int arr1[10];
	int arr2[]={1,2,3,4,5,6};
	//01 00 00 00 02 00 00 00 03 00 00 00...
	//strcpy(arr1,arr2);

	my_memcpy(arr1,arr2,20);//内存拷贝
}

void* my_memmove(void* dest,const void* src,size_t count)
{
	void* ret=dest;
	assert(dest && src);
	if(dest<src)//从前向后拷  前->后
	{
		while(count--)
		{
			*(char*)dest=*(char*)src;
			dest=(char*)dest+1;
			src=(char*)src+1;
		}
	}
	else        //后->前
	{
		while(count--)
		{
			*((char*)dest+count)=*((char*)src+count);
		}
	}
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	my_memmove(arr+2,arr,16);
}
