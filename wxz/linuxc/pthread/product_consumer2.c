/*************************************************************************
	> File Name: product_consumer2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月20日 星期三 11时32分16秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5
int queue[N];

sem_t blank;
sem_t point;

int put=0;
int take=0;
int cnt=0;

pthread_mutex_t mutex;

void *product(void* arg)
{
    while(1)
    {
        sem_wait(&blank);//--
        pthread_mutex_lock(&mutex);
        queue[put]=cnt;
        cnt++;
        put++;
        if(put==N)
          put=0;
        printf("-product--------%d\n,index--%d\n",queue[put],put);

        sem_post(&point);//++
        pthread_mutex_unlock(&mutex);
        /*put++;
        if(put==N)
            put=0;*/
       // sleep(1);
    }
}
void* consumer(void* arg)
{
    while(1)
    {
        sem_wait(&point);//--
        pthread_mutex_lock(&mutex);

        queue[take]=0;
        take++;
        if(take==N)
           take=0;
        printf("-consumer-------%d\n,index-----%d\n",queue[take],take);

        sem_post(&blank);//++
        pthread_mutex_unlock(&mutex);
        /*take++;
        if(take==N)
            take=0;*/
        sleep(1);
    }
}
int main()
{
    pthread_t cid,pid;
    sem_init(&blank,0,N);
    sem_init(&point,0,0);

    pthread_mutex_init(&mutex,NULL);

    pthread_create(&pid,NULL,(void *)product,NULL);
	pthread_create(&cid,NULL,(void *)consumer,NULL);

	pthread_join(pid,NULL);
	pthread_join(cid,NULL);

	sem_destroy(&blank);
	sem_destroy(&point);
}
