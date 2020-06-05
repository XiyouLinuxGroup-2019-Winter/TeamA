#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_once_t once=PTHREAD_ONCE_INIT;
void run(void)
{
	printf("the thread ID is :%u\n",pthread_self());
}
void *thread1(void *arg)
{
	printf("thread1 ID %u\n",pthread_self());
	pthread_once(&once,run);
	printf("thread1 end\n");
}
void  *thread2(void *arg)
{
	
	printf("thread2 ID %u\n",pthread_self());
	pthread_once(&once,run);
	printf("thread2 end\n");
}

int main()
{

	pthread_t thid1,thid2;
	printf("main ID %u \n",pthread_self());
	pthread_create(&thid1,NULL,thread1,NULL);
	pthread_create(&thid2,NULL,thread2,NULL);
//	sleep(3);
	printf("main thread exit\n");
	exit(0);
}


