#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
pthread_mutex_t mutex;
char * buf[10];
int pos;

void *thid(void*p)
{
	pthread_mutex_lock(&mutex);
	buf[pos]=(char *)p;
	sleep(1);
	pos++;
	pthread_mutex_unlock(&mutex);
}


int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_t thid1,thid2;
	pthread_create(&thid1,NULL,thid,(void *)"asdf");
	pthread_create(&thid2,NULL,thid,(void *)"zxcvb");
	sleep(10);
	pthread_join(thid1,NULL);
	pthread_join(thid2,NULL);
	pthread_mutex_destroy(&mutex);
	int i=0;
	for(i=0;i<pos;++i)
		printf("%s ",buf[i]);
	printf("....../n");
	return 0;
}


