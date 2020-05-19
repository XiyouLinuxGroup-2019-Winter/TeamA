/*************************************************************************
	> File Name: createthread.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月15日 星期五 01时22分40秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int* thread(void* arg)
{
    pthread_t newthid;
    newthid=pthread_self();
    printf("this is new thread,thread ID =%lu\n",newthid);
    return NULL;
}
int main()
{
    pthread_t thid;
    printf("main thread ,ID is %lu\n",pthread_self());
    if(pthread_create(&thid,NULL,(void*)thread,NULL))
    {
        printf("create failed\n");
        exit(1);
    }
    sleep(1);
    exit(0);
}
