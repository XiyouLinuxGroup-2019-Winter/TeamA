#define MAXSIZE 10
#define ERROR 0
#define OK 1
typedef int Status;
typedef int QElemType;
 typedef struct
{
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue*Q);
int QueueLength(SqQueue Q);
Status EnQueue(SqQueue *Q,QElemType e);
Status DeQueue(SqQueue *Q,QElemType *e);
