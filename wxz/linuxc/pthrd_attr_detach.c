/*************************************************************************
	> File Name: pthrd_create.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月20日 星期一 03时45分27秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
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
    pthread_attr_t attr;
    int ret;
    ret=pthread_attr_init(&attr);
    
    ret=pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);//设置线程属性为分离属性

    ret=pthread_create(&tid,&attr,tfn,NULL);

    ret=pthread_attr_destroy(&attr);

    pthread_join(tid,NULL);
    if(ret!=0)
    {
        fprintf(stderr,"attr_destroy error:%s\n",strerror(ret));
        exit(1);
    }
    printf("main:pid=%d,tid=%lu\n",getpid(),pthread_self());
    
    //sleep(1);
    pthread_exit((void*)0);
}
