#include<stdio.h>
#include<pthread.h>
 
int buffer[10],top = 0,itime = 0,itime2 = 0;
 
pthread_t thread[2];
pthread_mutex_t mut;
pthread_mutex_t mut2;
 
void producer()
{
	while(1)
	{
		if(itime == 10) return;
		pthread_mutex_lock(&mut);
		if(top == 10)
		{
			printf("buffer is full...producer is waiting...\n");
			pthread_mutex_unlock(&mut2);
			continue;
		}
		printf("pruducter set the %d\n", itime);
		top++;
		itime++;
		pthread_mutex_unlock(&mut2);
	}
}
 
 
void consumer()
{
	while(1)
	{
		if(itime2 == 10) return;
		pthread_mutex_lock(&mut2);
		if(top == 0)
		{
			printf("buffer is empty...consumer is waiting...\n");
			pthread_mutex_unlock(&mut);
			continue;
		}
		printf("consumer get the %d\n", itime2);
		top--;
		itime2++;
		pthread_mutex_unlock(&mut);
	}
}
 
int main()
{
	pthread_create(&thread[0], NULL, (void*)(&producer), NULL);	
	pthread_create(&thread[1], NULL, (void*)(&consumer), NULL);	
	
	sleep(1);
	return 0;
}
