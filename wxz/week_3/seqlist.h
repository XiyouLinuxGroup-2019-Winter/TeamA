/*************************************************************************
	> File Name: seqlist.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 12时04分39秒
 ************************************************************************/

#ifndef _SEQLIST_H
#define _SEQLIST_H
#define maxlen 100
typedef struct {
    char key[10];
    char name[20];
    int age;
}DATA;

typedef struct{
    DATA ListData[maxlen+1];
    int len;
}SLT;

void SLTInit(SLT* SL);
int SLTLength(SLT* SL);
int SLTInsert(SLT* SL,int n,DATA data);
int SLTAdd(SLT* SL,DATA data);
int SLTDelete(SLT* SL,int n);
DATA* SLTFind_n(SLT* SL,int n);
int SLTFind_key(SLT* SL,char* key);
int SLTPrint(SLT*SL);
#endif
