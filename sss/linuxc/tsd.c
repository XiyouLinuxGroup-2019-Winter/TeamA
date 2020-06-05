#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
pthread_key_t key;
void * thid2()
{
        int	tsd=2;
	pthread_setspecific(key,(void *)tsd);

	printf("%d",pthread_getspecific(key));	
}


void * thid1()

{

	int tsd=0;
	printf("theread %u is running",pthread_self());
	pthread_setspecific(key,(void *)tsd);
	pthread_t thid;
	pthread_create(&thid,NULL,thid2,NULL);

//	sleep(5);
	printf("%d",pthread_getspecific(key));
}

int main()
{

	pthread_t thid;
	printf("main ID :%u\n",pthread_self());
        pthread_key_create(&key,NULL);
	pthread_create(&thid,NULL,thid1,NULL);
        pthread_key_delete(key);
	printf("END!");
	return 0;
}


