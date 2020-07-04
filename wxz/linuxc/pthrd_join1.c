/*************************************************************************
	> File Name: pthrd_join.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月20日 星期一 23时17分03秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

void* tfn(void* arg)
{
    return (void*)74;
}
int main()
{
    pthread_t tid;
    struct thrd* retval;
    int ret;
    ret=pthread_create(&tid,NULL,tfn,NULL);

    pthread_join(tid,(void**)&retval);

    printf("child thread exit with %d\n",(void*)retval);
    pthread_exit(NULL);
}

