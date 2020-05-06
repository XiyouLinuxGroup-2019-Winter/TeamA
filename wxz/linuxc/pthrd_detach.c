/*************************************************************************
	> File Name: pthrd_create.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月20日 星期一 03时45分27秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *tfn(void* arg)
{
    printf("thread:pid=%d,tid=%lu\n",getpid(),pthread_self());
    return NULL;
}
int main()
{
    pthread_t tid;

    int ret=pthread_create(&tid,NULL,tfn,NULL);
    ret=pthread_detach(tid);
    sleep(1);
    ret=pthread_join(tid,NULL);
    printf("join ret=%d\n",ret);
    printf("main:pid=%d,tid=%lu\n",getpid(),pthread_self());

    
    //sleep(1);
    pthread_exit((void*)0);
}
