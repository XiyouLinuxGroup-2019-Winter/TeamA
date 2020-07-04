/*************************************************************************
	> File Name: mutex.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月15日 星期五 17时03分35秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
pthread_mutex_t number_mutex;
int globalnumber;
void *write_globalunmber(void* arg)
{
    pthread_mutex_lock(&number_mutex);
    globalnumber++;
    pthread_mutex_unlock(&number_mutex);
  //  printf("write_globalunmber:%d\n",globalnumber);
}
void* read_globalunmber(void* arg)
{
    int temp;
    pthread_mutex_lock(&number_mutex);
    temp=globalnumber;
    pthread_mutex_unlock(&number_mutex);
//    printf("read_globalunmber:%d\n",globalnumber);
}
int main()
{
    pthread_t thid1,thid2;
    pthread_create(&thid1,NULL,(void*)write_globalunmber,NULL);
 
    printf("write_globalunmber:%d\n",globalnumber);
    pthread_create(&thid2,NULL,(void*)read_globalunmber,NULL);

    printf("read_globalunmber:%d\n",globalnumber);
}
