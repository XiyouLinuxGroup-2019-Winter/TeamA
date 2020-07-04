/*************************************************************************
	> File Name: pthrd_shared.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月22日 星期三 02时31分58秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
pthread_mutex_t mutex;

void* tfn(void* arg)
{
    srand(time(NULL));
    while(1)
    {
        pthread_mutex_lock(&mutex);//加锁
        printf("hello");
        sleep(rand()%1);
        printf("world\n");
        sleep(rand()%1);

        pthread_mutex_unlock(&mutex);

        //sleep(rand()%3);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    srand(time(NULL));
    int ret=pthread_mutex_init(&mutex,NULL);

    pthread_create(&tid,NULL,tfn,NULL);
    while(1)
    {
        pthread_mutex_lock(&mutex);
        printf("HELLO ");
        sleep(rand()%1);
        printf("WORLD\n");
        sleep(rand()%1);

        pthread_mutex_unlock(&mutex);

        //sleep(rand()%3);
    }
    pthread_join(tid,NULL);
    pthread_mutex_destroy(&mutex);
}
