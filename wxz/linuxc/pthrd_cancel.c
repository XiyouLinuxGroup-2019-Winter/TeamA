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
    while(1)
    {
        printf(" thread :pid=%d ,tid=%lu\n",getpid(),pthread_self());
        sleep(1);
    }
    return NULL;
}
int main()
{
    int ret;
    pthread_t tid;
    

    ret=pthread_create(&tid,NULL,tfn,NULL);

    printf("main:pid=%d,tid=%lu\n",getpid(),pthread_self());
    sleep(5);
    ret=pthread_cancel(tid);//终止线程
    while(1);
    pthread_exit(NULL);

}
