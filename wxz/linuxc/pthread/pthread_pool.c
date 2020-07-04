/*************************************************************************
	> File Name: pthread_pool.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月20日 星期三 15时05分20秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>


typedef struct {
    void *(*function)(void*);
    void* arg;
}threadpool_task_t;


typedef struct threadpool_t
{
    pthread_mutex_t lock;
    pthread_mutex_t thread_counter;

    pthread_cond_t queue_not_full;
    pthread_cond_t queue_not_empty;

    pthread_t *threads;
    pthread_t adjust_tid;
    threadpool_task_t *task_queue;

    int min_thr_num;
    int max_thr_num;
    int live_thr_num;
    int busy_thr_num;
    int wait_exit_thr_num;

    int queue_front;                  
    int queue_rear;  
    int queue_size;
    int queue_max_size;
    
    int shutdown;
}threadpool_t;

threadpool_t *thread_create(int min_thr_num,int max_thr_num,int queue_max_size);
void *threadpool_thread(void *threadpool);
void *adjust_thread(void *threadpool);
int is_thread_alive(pthread_t tid);
int threadpool_free(threadpool_t *pool);
int threadpool_destroy(threadpool_t *pool);


//threadpool_create(3,100,100);
threadpool_t *thread_create(int min_thr_num,int max_thr_num,int queue_max_size)
{
    int i;
    threadpool_t *pool=NULL;

    do
    {
        if((pool=(threadpool_t*)malloc(sizeof(threadpool_t)))==NULL)
        {
            printf("malloc fail");
            break;
        }

        pool->min_thr_num=min_thr_num;
        pool->max_thr_num=max_thr_num;
        pool->busy_thr_num=0;
        pool->live_thr_num=min_thr_num;
        pool->wait_exit_thr_num=0;
        pool->queue_size=0;
        pool->queue_max_size=queue_max_size;
        pool->queue_front=0;
        pool->queue_rear=0;
        pool->shutdown=false;

        pool->threads=(pthread_t *)malloc(sizeof(pthread_t)*max_thr_num);
        if(pool->threads==NULL)
        {
            printf("malloc fail");
            break;
        }

        memset(pool->threads,0,sizeof(pthread_t)*max_thr_num);

        pool->task_queue=(threadpool_task_t*)malloc(sizeof(threadpool_task_t)*queue_max_size);
        if(pool->task_queue==NULL)
        {
            printf("malloc fail");
            break;
        }

        if( pthread_mutex_init(&(pool->lock),NULL)!=0 ||
            pthread_mutex_init(&(pool->thread_counter),NULL)!=0 ||
            pthread_cond_init(&(pool->queue_not_full),NULL)!=0 ||
            pthread_cond_init(&(pool->queue_not_empty),NULL)!=0)
            {
                printf("init the lock or cond fail");
                break;
            }

        for(i=0;i<min_thr_num;i++)
        {
            pthread_create(&(pool->threads[i]),NULL,threadpool_thread,(void*)pool);
            printf("start thread %x ------\n",(unsigned int)pool->threads[i]);
        }
        pthread_create(&(pool->adjust_tid),NULL,adjust_thread,(void*)pool);
        return pool;
    } while (0);

    threadpool_free(pool);
    return NULL;
}

int threadpool_add(threadpool_t *pool,void *(*function)(void* arg),void *arg)
{
    pthread_mutex_lock(&(pool->lock));

    while((pool->queue_size==pool->queue_max_size)&&(!pool->shutdown))
    {
        pthread_cond_wait(&(pool->queue_not_full),&(pool->lock));

    }

    if(pool->shutdown)
    {
        pthread_mutex_unlock(&(pool->lock));
    }

    if(pool->task_queue[pool->queue_rear].arg!=NULL)
    {
        pool->task_queue[pool->queue_rear].arg=NULL;
    }

    pool->task_queue[pool->queue_rear].function=function;
    pool->task_queue[pool->queue_rear].arg=arg;

    pool->queue_rear=(pool->queue_rear+1)%pool->queue_max_size;
    pool->queue_size++;//向任务队列中添加一个任务

    pthread_cond_signal(&(pool->queue_not_empty));
    pthread_mutex_unlock(&(pool->lock));
}
int threadpool_destroy(threadpool_t *pool)
{
    int i;
    if(pool==NULL)
        return -1;

    pool->shutdown=true;

    pthread_join(pool->adjust_tid,NULL);

    for(i=0;i<pool->live_thr_num;i++)
    {
        pthread_cond_broadcast(&(pool->queue_not_empty));
    }

    for(i=0;i<pool->live_thr_num;i++)
    {
        pthread_join(pool->threads[i],NULL);
    }
    threadpool_free(pool);
}
int threadpool_free(threadpool_t *pool)
{
    if (pool==NULL) 
        return -1;

    if (pool->task_queue) 
    {
        free(pool->task_queue);
    }
    if (pool->threads) 
    {
        free(pool->threads);
        pthread_mutex_lock(&(pool->lock));
        pthread_mutex_destroy(&(pool->lock));
        pthread_mutex_lock(&(pool->thread_counter));
        pthread_mutex_destroy(&(pool->thread_counter));
        pthread_cond_destroy(&(pool->queue_not_empty));
        pthread_cond_destroy(&(pool->queue_not_full));
    }
    free(pool);
    pool=NULL;

}

int is_thread_alive(pthread_t tid)
{
    int kill_rc=pthread_kill(tid, 0);     
    if(kill_rc==ESRCH) 
    {
        return false;
    }

    return true;
}


void *threadpool_thread(void* threadpool)
{
    threadpool_t *pool=(threadpool_t *)threadpool;
    threadpool_task_t task;
    while(1)
    {
        pthread_mutex_lock(&(pool->lock));

        while((pool->queue_size==0) && (!pool->shutdown))
        {
            pthread_cond_wait(&(pool->queue_not_empty),&(pool->lock));

            if(pool->wait_exit_thr_num>0)
                pool->wait_exit_thr_num--;
            
            if(pool->live_thr_num>pool->min_thr_num)
            {
                pool->live_thr_num--;
                pthread_mutex_unlock(&(pool->lock));
                pthread_exit(NULL);
            }
        }
    }

    if(pool->shutdown)


    task.function=pool->task_queue[pool->queue_front].function;
    task.arg=pool->task_queue[pool->queue_front].arg;

    pool->queue_front=(pool->queue_front+1)%pool->queue_max_size;
    pool->queue_size--;

    pthread_cond_signal(&(pool->queue_not_full));

    pthread_mutex_unlock(&(pool->lock));

    pthread_mutex_lock(&(pool->lock));
    pool->busy_thr_num++;
    pthread_mutex_unlock(&(pool->lock));

    (*(task.function))(task.arg);    
    //task.function(task.arg);

    pthread_mutex_lock(&(pool->lock));
    pool->busy_thr_num--;
    pthread_mutex_unlock(&(pool->lock));
    
    
}
void *adjust_thread(void* threadpool)
{
    int i;
    threadpool_t* pool=(threadpool_t*)threadpool;
    while(!pool->shutdown)
    {
        sleep(10);
        pthread_mutex_lock(&(pool->lock));
        int queue_size=pool->queue_size;
        int live_thr_num=pool->live_thr_num;
        pthread_mutex_unlock(&(pool->lock));

        pthread_mutex_lock(&(pool->thread_counter));
        int busy_thr_num=pool->busy_thr_num;
        pthread_mutex_unlock(&(pool->thread_counter));

        if(queue_size>=10 && live_thr_num < pool->max_thr_num) 
        {
            pthread_mutex_lock(&(pool->lock));  
            int add = 0;
         
            for(i=0;i<pool->max_thr_num && add<10
                    && pool->live_thr_num < pool->max_thr_num; i++) 
            {
                if (pool->threads[i] == 0 || !is_thread_alive(pool->threads[i])) 
                {
                    pthread_create(&(pool->threads[i]),NULL,threadpool_thread,(void *)pool);
                    add++;
                    pool->live_thr_num++;
                }
            }
            pthread_mutex_unlock(&(pool->lock));
        }

        
        if ((busy_thr_num * 2) < live_thr_num  &&  live_thr_num > pool->min_thr_num)
        {

            pthread_mutex_lock(&(pool->lock));
            pool->wait_exit_thr_num = 10;      /* 要销毁的线程数 设置为10 */
            pthread_mutex_unlock(&(pool->lock));

            for(i=0;i<10; i++) 
            {
                pthread_cond_signal(&(pool->queue_not_empty));
            }
        }
    }

    return NULL;
}
void *process(void* arg)
{
    printf("thread 0x%x working on task %d\n ",(unsigned int)pthread_self(),*(int *)arg);
    sleep(1);
    printf("task %d is end\n",*(int *)arg);

    return NULL;
}
int main()
{
    //threadpool_t *thread_create(int min_thr_num,int max_thr_num,int queue_max_size)
    threadpool_t *thp=thread_create(3,100,100);

    int num[20],i;
    for(i=0;i<20;i++)
    {
        num[i]=i;
        printf("add task %d\n",num[i]);

        //int threadpool_add(threadpool_t *pool,void *(*function)(void* arg),void *arg)
        threadpool_add(thp,process,(void*)&num[i]);
    }

    sleep(10);
    threadpool_destroy(thp);
}
