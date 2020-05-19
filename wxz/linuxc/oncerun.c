/*************************************************************************
	> File Name: oncerun.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月15日 星期五 01时27分05秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_once_t once=PTHREAD_ONCE_INIT;

void run()
{
    printf("Function run is running in thread %lu\n",pthread_self());
}
void *thread1(void* arg)
{
    pthread_t thid=pthread_self();
    printf("Current thread ID is %lu\n",thid);
    pthread_once(&once,run);
    printf("thread1 ends\n");
}
void *thread2(void *arg)
{
    pthread_t thid=pthread_self();
    printf("Current thread ID is %lu\n",thid);
    pthread_once(&once,run);
    printf("thread2 ends\n");
}
int main()
{
    pthread_t thid1,thid2;
    pthread_create(&thid1,NULL,thread1,NULL);
    pthread_create(&thid2,NULL,thread2,NULL);
    sleep(3);
    printf(",main thread exit!\n");
}
