/*************************************************************************
	> File Name: pro_cus.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月21日 星期四 15时49分09秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM 10

typedef struct prodcons
{
    int buffer[NUM];
    pthread_mutex_t lock;
    int read;
    int write;
    pthread_cond_t point;
    pthread_cond_t blank;
}prodcons;
void init(prodcons* ret)
{
    printf("初始化资源池\n");
    sleep(1);
    pthread_mutex_init(&ret->lock,NULL);
    pthread_cond_init(&ret->point,NULL);
    pthread_cond_init(&ret->blank,NULL);
    ret->read=0;
    ret->write=0;
}
void put(prodcons* ret,int data)
{
    pthread_mutex_lock(&ret->lock);
    while((ret->write+1)%NUM == ret->read)
    {
        printf("队列已满，等待消费者消耗---\n");
        pthread_cond_wait(&ret->blank,&ret->lock);
    }
    ret->buffer[ret->write]=data;
    ret->write++;
    if(ret->write==NUM)
        ret->write=0;

    pthread_cond_signal(&ret->point);
    pthread_mutex_unlock(&ret->lock);
}

int get(prodcons* ret)
{
    int data;
    pthread_mutex_lock(&ret->lock);
    while(ret->write==ret->read)
    {
        printf("队列中没有产品，等待生产者生产 ----\n");
        pthread_cond_wait(&ret->point,&ret->lock);
    }
    data=ret->buffer[ret->read];
    ret->read++;
    if(ret->read==NUM)
        ret->read=0;
    pthread_cond_signal(&ret->blank);
    pthread_mutex_unlock(&ret->lock);
    return data;
}
struct prodcons queue;
void *product(void* arg)
{
    int i;
    for(i=0;i<30;i++)
    {
        printf("开始生产 -----%d\n",i);
        put(&queue,i);
        printf("生产完成! --%d\n",i);
    }
    put(&queue,-1);
    printf("生产者完成工作\n");
}
void* consumer(void* arg)
{
    int d=-1;
    while(1)
    {
        printf("开始消费 %d\n",++d);
        d=get(&queue);
        printf("消费完成！--%d\n",d);
        if(d==-1)
            break;
    }
    printf("消费者完成工作\n");
}
int main()
{
    pthread_t tid,cid;
    init(&queue);
    pthread_create(&tid,NULL,product,0);
    pthread_create(&cid,NULL,consumer,0);

    pthread_join(tid,NULL);
    pthread_join(cid,NULL);
}
