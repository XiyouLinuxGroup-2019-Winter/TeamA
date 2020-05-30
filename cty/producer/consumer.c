#include<stdio.h>
#include<pthread.h>
 
int buffer[20],t = 0,time1 = 0,time2 = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t thread[2];
pthread_mutex_t mut;
pthread_mutex_t mut2;
 
void producer()
{
	while(1)
	{
		if(time1 == 20) 
		return;
		pthread_mutex_lock(&mut);
		if(t == 20)
		{
			printf("缓冲区阻塞，生产者等待。\n");
			pthread_mutex_unlock(&mut2);
			continue;
		}
		printf("生产者位于%d\n", time1);
		t++;
		time1++;
		pthread_mutex_unlock(&mut2);
	}
}
 
 
void consumer()
{
	while(1)
	{
		if(time2 == 20) 
		return;
		pthread_mutex_lock(&mut2);
		if(t == 0)
		{
			printf("缓冲区空了，消费者等待\n");
			pthread_mutex_unlock(&mut);
			continue;
		}
		printf("消费者得到%d\n", time2);
		t--;
		time2;
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
