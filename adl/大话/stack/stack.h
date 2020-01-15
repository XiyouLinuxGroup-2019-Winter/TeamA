#define MAXSIZE 10
#define ERROR 0
#define OK 1
typedef int Status;
typedef char SElemType;
typedef struct 
{
    SElemType data[MAXSIZE];
    int top;
}Sqstack;

Status InitStack(Sqstack*S);
// Destory(*S);
// ClearStack(*S);
// StackEmpty(*S);
// GetTop(S,*e);
Status Push(Sqstack*S,SElemType e);
Status Pop(Sqstack*S,SElemType* e);
// StackLength(Sqstack S);