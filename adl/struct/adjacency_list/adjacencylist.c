#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct EdgeNode
{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
} EdgeNode;
typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];
typedef struct
{
    AdjList adjlist;
    int numVertexes, numEdges;
} GraphAdjList;
void CreatALGraph(GraphAdjList *G)
{
    int i, j, k, w;
    EdgeNode *e;
    printf("输入顶点数和边数\n");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    while (getchar() != '\n')
        continue;
    for (i = 0; i < G->numVertexes; i++)
    {
        puts("输入顶点信息");
        scanf("%c", &G->adjlist[i].data);
        while (getchar() != '\n')
            continue;
        G->adjlist[i].firstedge = NULL;
    }
    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi,vj)上的顶点序号和他们的权w:\n");
        scanf("%d%d%d", &i, &j, &w);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->weight = w;
        e->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge = e;
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->weight = w;
        e->next = G->adjlist[j].firstedge;
        G->adjlist[j].firstedge = e;
    }
}

int main()
{
    VertexType c1, c2;
    GraphAdjList G;
    CreatALGraph(&G);
    puts("输入你想要查找的两个顶点的data");
    while(getchar()!='\n')
    continue;
    scanf("%c%c", &c1, &c2);
    int flag=0;
    for (int i = 0; i < G.numVertexes; i++)
    {
        if (G.adjlist[i].data==c1)
        {
            EdgeNode *cur = G.adjlist[i].firstedge;
            while (cur != NULL &&G.adjlist[cur->adjvex].data!=c2)
                cur=cur->next;
            if (cur)
            {
                flag=1;
                printf("权重是%d\n", cur->weight);
                break;
            }
            else
            printf("can't find it");    
        }
    }
    if(!flag)
        printf("can't find it\n");
}