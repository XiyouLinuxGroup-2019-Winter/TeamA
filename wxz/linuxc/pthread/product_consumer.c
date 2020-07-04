/*************************************************************************
	> File Name: product_consumer.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月20日 星期三 02时23分43秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int cnt=0;

void *product(void *arg)
{    
    while(1)
    {
        pthread_mutex_lock(&mutex);
        cnt++;
        printf("-product %d\n",cnt);
        //sleep(1);
        pthread_mutex_unlock(&mutex);
        sleep(1);
        pthread_cond_signal(&cond);
        //sleep(1);
    }
}

void *consumer(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
    
        while(cnt<=0)
        {
            pthread_cond_wait(&cond,&mutex);
        }
        cnt--;
        printf("-consumer %lu----------%d\n",pthread_self(),cnt);
        //sleep(1);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main()
{
    pthread_t pid,cid;
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);

    pthread_create(&pid,NULL,(void *)product,NULL);
    pthread_create(&cid,NULL,(void *)consumer,NULL);
    
    pthread_join(pid,NULL);
    pthread_join(cid,NULL);
}

