/*************************************************************************
	> File Name: linkqueue.h
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 22时12分49秒
 ************************************************************************/

#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

typedef void LinkQueue;
LinkQueue* LinkQueue_Create();
void LinkQueue_Destroy(LinkQueue* queue);
void LinkQueue_Clear(LinkQueue* queue);
int LinkQueue_Append(LinkQueue* queue, void* item);
void* LinkQueue_Retrieve(LinkQueue* queue);
void* LinkQueue_Header(LinkQueue* queue);
int LinkQueue_Length(LinkQueue* queue);

#endif
