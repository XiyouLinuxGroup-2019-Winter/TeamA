#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
int * thread(void *arg)
{
	printf("-");
	printf("the thread ID :%u",pthread_self());
	return NULL;
}

int main(void)
{
	pthread_t thid;
	printf("main thread ID : %u",pthread_self());
	pthread_create(&thid,NULL,(void *)thread,NULL);
	return 0;
}

