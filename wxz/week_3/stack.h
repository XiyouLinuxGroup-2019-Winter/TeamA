/*************************************************************************
	> File Name: stack.h
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 02时52分10秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
#define maxlen 50
typedef struct
{
    char name[10];
    int age;
}DATA;

typedef struct stack{
    DATA data[size+1];
    int top;
}Stack;
Stack* STLInit();
int SLTIsEmpty(Stack* SL);
int STLIsFull(Stack* SL);
void STLClear(Stack* SL)
void SLTFree(Stack* SL,DATA data);
int PushSTL(Stack* SL,DATA data);
DATA PopSTL(Stack* SL);
DATA PeeckSTL(Stack* SL);
#endif
