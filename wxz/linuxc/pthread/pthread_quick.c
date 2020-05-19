/*************************************************************************
	> File Name: pthread_quick.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 16时18分41秒
 ************************************************************************/

#include<stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_NUM=1e8L;
#define MAX=1e7L;
int thread=100;
int thread_num=MAX_NUM/thread;
int num[MAX_NUM];
int tmp_num[MAX_NUM];
pthread_barrier_t barrier;

void init()
{
    srand(1);
    for(int i=0;i<MAX_NUM;i++)
        num[i]=rand()%MAX;
}
void qsorts(int *start,int* end)
{
    int nums=end-start;
    if(num>0)
    {
        int flag=start[0];
        int i=0;
        int j=nums;
        while(i<j)
        {
            while(j>i && start[j]>flag)
                --j;
            start[i]=start[j];
            while(i<j && start[i]<=flag)
                ++i;
            start[j]=start[i];

        }
        start[i]=flag;

        qsorts(start,start+i-1);
        qsorts(start+i+1,end);

    }
}
void *play(void *arg)
{
    long long int index=(long long int)arg;
    qsorts(num+index,num+index+thread_num-1);
    pthread_barrier_wait(&barrier);
    pthread_exit(NULL);
}
void meger()
{
    long index[thread];
    for(int i=0;i<thread;i++)
    {
        index[i]=i*thread_num;
    }
    for(long i=0;i<MAX_NUM;i++)
    {
        long min_index;
        long min_num=MAX;
        for(int j=0;j<thread;j++)
        {
            if((index[i]<(j+1)*thread_num) && (num[index[j]]<min_num))
            {
                min_index=j;
                min_num=num[index[j]];
            }
        }
        tmp_num[i]=num[index[min_index]];
        index[min_index]++;
    }
}
int main()
{
    init();
    struct timeval start,end;
    pthread_t pid;
    printf("%ld %ld\n",num[1],num[2]);

    gettimeofday(&start,NULL);

    pthread_barrier_wait(&barrier);
    for(int i=0;i<thread;i++)
        pthread_create(&pid,NULL,play,(void*)(i*thread_num));
    meger();

    gettimeofday(&end, NULL);
    long long s_usec = start.tv_sec * 1000000 + start.tv_usec;
    long long e_usec = end.tv_sec * 1000000 + end.tv_usec;

    double useTime = (double)(e_usec - s_usec) / 1000000.0;
    printf("sort use %.4f seconds\n", useTime);

}
