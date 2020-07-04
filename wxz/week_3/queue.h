/*************************************************************************
	> File Name: queue.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 18时17分24秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H
#define len 15
typedef struct{
    char name[10];
    int age;
}DATA;
typedef struct{
    DATA data[len];
    int head;
    int tail;
}SQT;
SQT* SQTInit();
int SQTIsEmpty(SQT* p);
int InSQT(SQT* p,DATA data);
void SQTFree(SQT* p);mZ
DATA *PeekSQT(SQT* p);
int SQTLength(SQT* p);

#endif
