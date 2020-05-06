#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t ret;
	printf("before fork");//没有换行符，此时被挤压到printf（）的库缓存中，
	//被复制到子进程
	ret=fork();

	if(ret>0)
	{
		printf("parent PID=%d\n",getpid());

		printf("parent ret=%d\n",ret);
	}
	else if(ret==0)
	{
		printf("child PID=%d\n",getpid());//此时 把积压的数值也打印出来
		printf("child ret=%d\n",ret);
	}
}

