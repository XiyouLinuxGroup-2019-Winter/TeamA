#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
pthread_key_t key;
void*thread2(void *arg)
{
    int tsd=5;
    printf("thread %ld is running \n",pthread_self());
    pthread_setspecific(key,(void*)tsd);
    printf("thread %ld return %d\n",pthread_self(),pthread_getspecific(key));
//    pthread_exit(0);
}
void*thread1(void *arg)
{
    int tsd=0;
    pthread_t thid2;
    int status2;
    printf("thread %ld is running \n",pthread_self());
    pthread_setspecific(key,(void*)tsd);
    pthread_create(&thid2,NULL,thread2,NULL);
    pthread_join(thid2,(void*)&status2);
    //sleep(5);
    //printf("wrong\n");
    printf("thread %ld returns %d\n",pthread_self(),pthread_getspecific(key));
  //  pthread_exit(0);
}
int main()
{
    pthread_t thid1;
    int status1;
    printf("main thread begins running \n");
    pthread_key_create(&key,NULL);
    pthread_create(&thid1,NULL,thread1,NULL);
    //sleep(10);
    if(pthread_join(thid1,(void*)&status1))
    perror("something wrong\n");
    pthread_key_delete(key);
    printf("main thread exit \n");
    return 0;
}