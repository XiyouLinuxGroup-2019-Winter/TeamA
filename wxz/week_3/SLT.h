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
#endif
