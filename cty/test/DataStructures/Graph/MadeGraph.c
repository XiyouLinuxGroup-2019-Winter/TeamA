#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 200
#define INFINITY 32767
typedef struct {
    int arcs[MAXVEX][MAXVEX];
    char vex[MAXVEX];
    int vexnum;
    int arcnum;
}AdiMatrix;
typedef struct Queue {
    char array[MAXVEX];
    int rear;
    int front;
}Queue;
void Init(Queue *q) {
    q->front = q->rear = MAXVEX;
}
void EnterQueue(Queue *q, char v0) {
    q->rear = (q->rear + 1) % MAXVEX;
    q->array[q->rear] = v0;
}
int Empty(Queue q) {
    if (q.rear == q.front) {
        return 1;
    } else {
        return 0;
    }
}
void DeleteQueue(Queue *q, char *v) {
    q->front = (q->front + 1) % MAXVEX;
    *v = q->array[q->front];
}

int LocateVex(AdiMatrix *g, char v) {
    for (int i = 1; i <= g->vexnum; i++) {
        if (g->vex[i] == v) {
            return i;
        }
    }
    return 0;
}
void Create(AdiMatrix *g) {
    scanf("%d %d", &g->vexnum, &g->arcnum);
    getchar();
    for (int i = 1; i <= g->vexnum; i++) {
        for (int j = 1; j <= g->vexnum; j++) {
            g->arcs[i][j] = 0;
        }
    }
    for (int i = 1; i <= g->vexnum; i++) {
        scanf("%c", &g->vex[i]);
    }
    for (int k = 1; k <= g->arcnum; k++) {
        char vex1, vex2;
        getchar();
        scanf("%c", &vex1);
        int i = LocateVex(g, vex1);
        scanf("%c", &vex2);
        int j = LocateVex(g, vex2);
        g->arcs[i][j] = 1;
    }
    
}
void Output(AdiMatrix *g) {
    for (int i = 1; i <= g->vexnum; i++) {
        int count1 = 0, count2 = 0;
        printf("%c ", g->vex[i]);
        for (int j = 1; j <= g->vexnum; j++) {
            if (g->arcs[i][j] == 1) {
                count1++;
            }
        }
        for (int k = 1; k <= g->vexnum; k++) {
            if (g->arcs[k][i] == 1) {
                count2++;
            }
        }
        printf("%d %d %d", count1, count2, count1 + count2);
        printf("\n");
    }
}
int visited[MAXVEX] = {0};
char FirstAdjVex(AdiMatrix *g, char v0) {
    int i;
    for (i = 1; i <= g->vexnum; i++) {
        if (g->vex[i] == v0) {
            break;
        }
    }
    for (int j = 1; j <= g->vexnum; j++) {
        if (g->arcs[i][j] == 1 && visited[g->vex[j]] == 0) {
            return g->vex[j];
        }
    }
    return -1;
}
int NextAdjVex(AdiMatrix *g, char v0, char w) {
    int i;
    for (i = 1; i <= g->vexnum; i++) {
        if (g->vex[i] == v0) {
            break;
        }
    }
    for (int j = 1; j <= g->vexnum; j++) {
        if (g->arcs[i][j] == 1 && g->vex[j] != w  && visited[g->vex[j]] == 0) {
            return g->vex[j];
        }
    }
    return -1;
}
void DFS(AdiMatrix *g, char v0) {
    printf("%c", v0);
    visited[v0] = 1;
    int w = FirstAdjVex(g, v0);
    while (w != -1) {
        if (!visited[w]) {
            DFS(g, w);
            //下面这个语句的执行是在回溯的时候进行的
            //系统内部的递归工作栈会把这一层的结果，变量保存，当我们递推结束
            //会开始回溯过程
            //在回溯过程中，我们要继续搜索其他顶点序列的其他路径
            //比如这个题，画个图容易看出是从A开始搜索，A->B，B->C, C->D，D后面没有字符了，这个时候开始回溯，返回到C这一层，C后面除了D没有其他路径了，而D我们已经搜索过，继续回溯，返回B这一层，B这一层与C那一层同理，继续回溯，返回A这一层，发现A还可以到E，下面这条语句就是为什么我们回溯过程可以发现A还可以有一条路径是A->E的。这一层我们的递归工作栈会保存刚才递推时的变量的值（v0 = A, w = B）。
            w = NextAdjVex(g, v0, w);
        }
    }
}
void TraverseG(AdiMatrix *g) {
    for (int i = 1; i <= g->vexnum; i++) {
        if (!visited[g->vex[i]]) {
            DFS(g, g->vex[i]);
        }
    }
}
void BFS(AdiMatrix *g, int v0) {
    printf("%c", v0);
    visited[v0] = 1;
    Queue q;
    Init(&q);
    EnterQueue(&q, v0);
    int w;
    while (!Empty(q)) {
        char v;
        DeleteQueue(&q, &v);
        w = FirstAdjVex(g, v);
        while (w != -1) {
            if (!visited[w]) {
                printf("%c", w);
                visited[w] = 1;
                EnterQueue(&q, w);
            }
            w = NextAdjVex(g, v, w);
        }
    }
}
void TraverseG2(AdiMatrix *g) {
    for (int i = 1; i <= g->vexnum; i++) {
        if (!visited[g->vex[i]]) {
            BFS(g, g->vex[i]);
        }
    }
}
int main(int argc, const char * argv[]) {
    AdiMatrix *g;
    g = (AdiMatrix *)malloc(sizeof(AdiMatrix));
    Create(g);
    Output(g);
    TraverseG(g);
    for (int i = 0; i < MAXVEX; i++) {
        visited[i] = 0;
    }
    printf("\n");
    TraverseG2(g);
    printf("\n");
    return 0;
}

