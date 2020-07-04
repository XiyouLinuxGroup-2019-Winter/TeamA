/*************************************************************************
	> File Name: pthrd_more.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月20日 星期一 13时56分05秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
void* tfn(void* arg)
{
    //int i=*((int*)arg);
    int i=(int)arg;
    sleep(i);
    printf("....I'm %dth thread :pid=%d ,tid=%lu\n",i+1,getpid(),pthread_self());
    return NULL;
}
int main()
{
    int i,ret;
    pthread_t tid;
    
    for(i=0;i<5;i++)
    ret=pthread_create(&tid,NULL,tfn,(void *)i);

    sleep(i);
    printf("main:I'm Main,pid=%d,tid=%lu\n",getpid(),pthread_self());
}
