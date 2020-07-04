/*************************************************************************
	> File Name: jointhread.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月15日 星期五 11时53分20秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
void assisthread(void* arg)
{
    printf(" I am helping to do some jobs\n");
    sleep(3);
    pthread_exit(-1);
}
int main()
{
    pthread_t assisthid;
    int status;
    pthread_create(&assisthid,NULL,(void*)assisthread,NULL);
    pthread_join(assisthid,(void*)&status);
    printf("assisthread;s exit is caused %d\n",status);
}
