/*************************************************************************
	> File Name: linkstack.h
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 16时52分33秒
 ************************************************************************/

#ifndef _LINKSTACK_H
#define _LINKSTACK_H

typedef void LinkStack;

LinkStack* LinkStack_Create();
void LinkStack_Destroy(LinkStack* stack);
void LinkStack_Clear(LinkStack* stack);
int LinkStack_Push(LinkStack* stack, void* item);
void* LinkStack_Pop(LinkStack* stack);
void* LinkStack_Top(LinkStack* stack);
int LinkStack_Size(LinkStack* stack);

#endif
