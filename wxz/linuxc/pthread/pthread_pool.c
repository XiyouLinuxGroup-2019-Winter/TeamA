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
#define LEFT 30000000
#define RIGHT 30000200
#define NUM 4
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
int num=0;

void *pthread_pool(void* arg)
{
    int i,j,flag;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(num==0)
        {
            pthread_mutex_unlock(&mutex);
            sched_yield();
            pthread_mutex_unlock(&mutex);
        }
        if(num==-1)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        i=num;
        num=0;
        pthread_mutex_unlock(&mutex);

        flag=1;
        for(j=2;j<i/2;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            printf("[%d]%d is a pthread\n",(int)arg,i);
        }
        pthread_exit(NULL);
    }
}
int main()
{
    int i,ret;
    pthread_t tid[NUM];
    for(i=0;i<NUM;i++)
    {
        ret=pthread_create(tid+i,NULL,pthread_pool,(void*)i);
        if(ret)
        {
            fprintf(stderr,"pthread_create():%s\n",strerror(ret));
            exit(1);
        }
    }

    for(i=LEFT;i<=RIGHT;i++)
    {
        pthread_mutex_lock(&mutex);
        while(num!=0)
        {
            pthread_mutex_unlock(&mutex);
            //sleep(1);
            sched_yield();
            pthread_mutex_lock(&mutex);
        }
        num=i;
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);
    while(num!=0)
    {
        pthread_mutex_unlock(&mutex);
        sched_yield();
        pthread_mutex_lock(&mutex);
    }
    num=-1;
    pthread_mutex_unlock(&mutex);

    for(i=0;i<NUM;i++)
        pthread_join(tid[i],NULL);
    pthread_mutex_destroy(&mutex);
}
