/*************************************************************************
	> File Name: conditionVar_product_consumer.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月26日 星期日 00时45分17秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#define NUM 5

int queue[NUM];
sem_t blank_number,product_number;



void* consumer(void* arg)
{
    
    int i=0;
    while(1)
    {
        sem_wait(&product_number);//--
        printf("-consumer----%d\n",queue[i]);
        queue[i]=0;
        sem_post(&blank_number);//++

        i=(i+1)%NUM;
        sleep(rand()%3);
    }
}
void* producer(void* arg)
{
        int i=0;
        while(1)
        {
            sem_wait(&blank_number);//--
            queue[i]=rand()%1000+1;
            printf("-producer-------%d\n",queue[i]);
    
            sem_post(&product_number);//++
            i=(i+1)%NUM;
            sleep(rand()%1);
        }
}
int main()
{
    pthread_t pid,cid;

    sem_init(&blank_number,0,NUM);
    sem_init(&product_number,0,0);

    pthread_create(&pid,NULL,producer,NULL);
    pthread_create(&cid,NULL,consumer,NULL);

    pthread_join(pid,NULL);
    pthread_join(cid,NULL);

    sem_destroy(&blank_number);
    sem_destroy(&product_number);
}
