/*************************************************************************
	> File Name: philosopher_dinner_3.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月20日 星期三 18时37分17秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5

sem_t chop[N];
sem_t sum;
pthread_mutex_t mutex;
int philosophers[N]={0,1,2,3,4};

void* philosopher(void* arg)
{
    int i=*(int*)arg;
    int left=i;
    int right=(i+1)%N;

    while(1)
    {
        sem_wait(&sum);
        sem_wait(&chop[left]);//--
        printf("philosopher %d ---拿起了一只%d筷子不能进餐\n",i,left);
        sem_wait(&chop[right]);
        printf("philosopher %d ---拿起了%d筷子\n",i,right);
        sleep(1);

        //printf("philosopher----%d\n",i);
        sleep(1);
        sem_post(&chop[left]);//++
        printf("philosopher %d ---放下了%d筷子\n",i,left);
        sem_post(&sum);
        sem_post(&chop[right]);//++
        printf("philosopher %d ---放下了%d筷子\n",i,right);
    }
}
int main()
{
    pthread_t tid[N];
    int i;
    for(i=0;i<N;i++)
        sem_init(&chop[i],0,1);

    sem_init(&sum,0,4);

    pthread_mutex_init(&mutex,NULL);

    for(i=0;i<N;i++)
        pthread_create(&tid[i],NULL,(void*)philosopher,&philosophers[i]);
    for(i=0;i<N;i++)
        pthread_join(tid[i],NULL);
    for (i=0;i<N;i++)
		sem_destroy(&chop[i]);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&sum);

}


