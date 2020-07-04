/*************************************************************************
	> File Name: deadlock.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月19日 星期二 18时20分33秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <pthread.h>

int var=1,num=5;
pthread_mutex_t m_var,m_num;
void* tfn(void*arg)
{
    int i=(int)arg;
    if(i==1)
    {
        pthread_mutex_lock(&m_var);
        var=22;
        sleep(1);

        pthread_mutex_lock(&m_num);
        num=66;
        
        pthread_mutex_unlock(&m_var);
        pthread_mutex_unlock(&m_num);
        printf("--------thread %d finish\n",i);
        pthread_exit(NULL);
    }
    else if(i==2)
    {
        pthread_mutex_lock(&m_num);
        var=33;
        sleep(1);
        pthread_mutex_lock(&m_var);
        num=99;
        
        pthread_mutex_unlock(&m_var);
        pthread_mutex_unlock(&m_num);
        printf("--------thread %d finish\n",i);
        pthread_exit(NULL);
    }
}
int main()
{
    pthread_t tid1,tid2;
    int ret1,ret2;

    pthread_mutex_init(&m_var,NULL);
    pthread_mutex_init(&m_num,NULL);

    pthread_create(&tid1,NULL,tfn,(void*)1);
    pthread_create(&tid2,NULL,tfn,(void*)2);
    sleep(3);

    printf("var=%d,num=%d\n",var,num);

    pthread_mutex_destroy(&m_var);
    pthread_mutex_destroy(&m_num);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}
/*int a=100;
int main()
{
    pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
    
    pthread_mutex_lock(&mutex);
    a=777;
    pthread_mutex_lock(&mutex);

    pthread_mutex_unlock(&mutex);

    printf("--------- a= %d\n",a);
    pthread_mutex_destroy(&mutex);
}*/
