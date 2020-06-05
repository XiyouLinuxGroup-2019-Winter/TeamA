#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void thread()
{
	printf("thread1...\n");
	pthread_exit(0);
}


int main()
{

	pthread_t thid;
	int status;
	pthread_create(&thid,NULL,(void *)thread,NULL);
	pthread_join(thid,(void*)&status);
	printf("%d",status);
}

