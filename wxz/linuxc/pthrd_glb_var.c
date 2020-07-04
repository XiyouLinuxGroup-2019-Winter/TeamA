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
int var=100;
void *tfn(void* arg)
{
    var=200;
    printf("thread:var=%d\n",var);
    return NULL;
}
int main()
{
    pthread_t tid;

    printf("at first var=%d\n",var);
    int ret=pthread_create(&tid,NULL,tfn,NULL);
    if(ret!=0)
        perror("pthread_create error");
    sleep(1);
    
    printf("after pthread_create ,var=%d\n",var);
}
