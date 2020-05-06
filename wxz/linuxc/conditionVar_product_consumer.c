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
struct msg{
    struct msg* next;
    int n;
};

struct msg* head;

pthread_cond_t has_product=PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

void* consumer(void* p)
{
    struct msg* mp;
    for(;;)
    {
        pthread_mutex_lock(&lock);
        while(head==NULL)
            pthread_cond_wait(&has_product,&lock);

        mp=head;
        head=mp->next;
        pthread_mutex_unlock(&lock);

        printf("-consumer %lu----%d\n",pthread_self(),mp->n);
        free(mp);
        sleep(rand()%5);
    }
}
void* producer(void* p)
{
    struct msg* mp;
    for(;;)
    {
        mp=malloc(sizeof(struct msg));
        mp->n=rand()%1000+1;
        printf("-producer-------%d\n",mp->n);

        pthread_mutex_lock(&lock);
        mp->next=head;
        head=mp;
        pthread_mutex_unlock(&lock);

        pthread_cond_signal(&has_product);
        sleep(rand()%5);
    }
}
int main()
{
    pthread_t pid,cid;
    pthread_create(&pid,NULL,producer,NULL);
    pthread_create(&cid,NULL,consumer,NULL);

    pthread_join(pid,NULL);
    pthread_join(cid,NULL);
}
