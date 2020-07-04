#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>

typedef struct threadpool_task_t
{
    void *(*func)(void* arg);
    void* arg;
}threadpool_task;

typedef struct threadpool_t
{
    int max_thr_num;
    int shutdown;

    threadpool_task *queue_task;
    int queue_front;                  
    int queue_rear;  
    int queue_size;
    int queue_max_size;

    pthread_t *threads;
    pthread_cond_t cond;
    pthread_mutex_t lock;


}threadpool_t;

void *threadpool_thread(void* threadpool);
threadpool_t *threadpool_create(int max_thr_num,int queue_max_size);
int threadpool_add(threadpool_t *pool,void *(*func)(void* arg),void *arg);
void threadpool_destroy(threadpool_t* pool);
void *func();


void *threadpool_thread(void* threadpool)
{
    threadpool_t *pool=(threadpool_t *)threadpool;
    threadpool_task task;
    while(1)
    {
        pthread_mutex_lock(&pool->lock);
        while((pool->queue_size==0)&&(!pool->shutdown))
        {
           // printf("thread 0x%x is waiting\n", (unsigned int)pthread_self());
            //printf("thread  %ld is ready \n",pthread_self());
            pthread_cond_wait(&pool->cond,&pool->lock);
            //printf("thread  %ld is weak up  \n",pthread_self());
        }
        if(pool->shutdown)
        {
            pthread_mutex_unlock(&pool->lock);
            pthread_exit(0);
        }
        else
        {
            task.func=pool->queue_task[pool->queue_front].func;
            task.arg=pool->queue_task[pool->queue_front].arg;
            pool->queue_front=(pool->queue_front+1)%pool->queue_max_size;
            pool->queue_size--;
            pthread_mutex_unlock(&pool->lock);

            task.func(task.arg);
            //((*task.func)(task.arg));
        }
    }
    //pthread_exit(NULL);
}
threadpool_t *threadpool_create(int max_thr_num,int queue_max_size)
{
    int i;
    threadpool_t *pool=(threadpool_t *)malloc(sizeof(threadpool_t));
    pool->shutdown=0;
    pool->max_thr_num=max_thr_num;
    pool->threads=(pthread_t*)malloc(sizeof(pthread_t)*max_thr_num);

    pool->queue_task=(threadpool_task*)malloc(sizeof(threadpool_task)*queue_max_size);
    pool->queue_size=0;
    pool->queue_max_size=queue_max_size;
    pool->queue_front=0;
    pool->queue_rear=0;

    pthread_mutex_init(&(pool->lock),NULL);
    pthread_cond_init(&(pool->cond),NULL);

    for(i=0;i<max_thr_num;i++)
    {
        pthread_create(&pool->threads[i],NULL,threadpool_thread,(void*)pool);
    }
    return pool;
}

int threadpool_add(threadpool_t *pool,void *(*func)(void* arg),void *arg)
{

    pthread_mutex_lock(&pool->lock);


    if(pool->queue_task[pool->queue_rear].arg!=NULL)
    {
        free(pool->queue_task[pool->queue_rear].arg);
        pool->queue_task[pool->queue_rear].arg = NULL;
    }
    pool->queue_task[pool->queue_rear].func=func;
    pool->queue_task[pool->queue_rear].arg=arg;

    pool->queue_rear=(pool->queue_rear+1)%pool->queue_max_size;
    pool->queue_size++;//向任务队列中添加一个任务

    pthread_cond_signal(&pool->cond);
    pthread_mutex_unlock(&pool->lock);
}
void threadpool_destroy(threadpool_t* pool)
{
    int i;
    printf("开始销毁\n");


    if(pool->shutdown)                        //先判断一下销毁标志是否已经销毁
    {
        return;
    }
    
    pool->shutdown=1;

    pthread_mutex_lock(&pool->lock);
    pthread_cond_broadcast(&pool->cond);
    pthread_mutex_unlock(&pool->lock);

    for(i=0;i<pool->max_thr_num;i++)
    {
        pthread_join(pool->threads[i],NULL);
    }
    free(pool->threads);

    /*if(pool->queue_task)
    {
        free(pool->queue_task);
    }

    if (pool->threads)
    {
        free(pool->threads);
        pthread_mutex_lock(&(pool->lock));
        pthread_mutex_destroy(&(pool->lock));
        pthread_cond_destroy(&(pool->cond));
    }
    free(pool);
    pool = NULL;*/
    pthread_mutex_lock(&pool->lock);
    pthread_mutex_destroy(&pool->lock);
    pthread_cond_destroy(&pool->cond);
    free(pool);
    printf("销毁完成\n");
}
void *func()
{
    printf("pthread id = %ld\n",pthread_self());
    sleep(3);
}
int main()
{
    int i;

    sleep(1);
    threadpool_t *pool=threadpool_create(10,10);
    for(i=0;i<10;i++)
    {
        threadpool_add(pool,func,NULL);
    }
    sleep(10);
    threadpool_destroy(pool);
}