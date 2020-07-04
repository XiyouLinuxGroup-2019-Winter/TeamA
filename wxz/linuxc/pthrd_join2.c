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
struct thrd{
    int var;
    char str[256];
};
void* tfn(void* arg)
{
    struct thrd* tval=(struct thrd*)arg;
    tval->var=100;
    strcpy(tval->str,"hello  thread");
    return (void*)tval;
}
int main()
{
    pthread_t tid;
    struct thrd arg;
    struct thrd* retval;
    int ret;
    ret=pthread_create(&tid,NULL,tfn,(void*)&arg);

    pthread_join(tid,(void**)&retval);

    printf("child thread exit with var=%d,str=%s\n",retval->var,retval->str);
    pthread_exit(NULL);
}

