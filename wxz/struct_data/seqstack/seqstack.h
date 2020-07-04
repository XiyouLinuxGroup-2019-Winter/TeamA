/*************************************************************************
	> File Name: seqstack.h
	> Author: 
	> Mail: 
	> Created Time: 2020年05月04日 星期一 20时44分58秒
 ************************************************************************/

#ifndef _SEQSTACK_H
#define _SEQSTACK_H
typedef void SeqStack;
 
SeqStack* SeqStack_Create(int capacity);
void SeqStack_Destroy(SeqStack* stack);
void SeqStack_Clear(SeqStack* stack);
int SeqStack_Push(SeqStack* stack, void* item);
void* SeqStack_Pop(SeqStack* stack);
void* SeqStack_Top(SeqStack* stack);
int SeqStack_Size(SeqStack* stack);
int SeqStack_Capacity(SeqStack* stack);
#endif
