#include <stdio.h>
typedef int VertexType; //顶点类型
typedef int EdgeType;
#define MAXVEX 100
#define INFINTY 65535
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;
void CreatMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("输入顶点数和边数:\n");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    printf("输入顶点信息:\n");
    for (i = 0; i < G->numVertexes; i++)
        scanf("%d", &G->vexs[i]);
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = INFINTY;
        }
    }
    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi,vj)上的下标i,下标j和权w.\n");
        scanf("%d%d%d", &i, &j, &w);
        G->arc[j][i] = G->arc[i][j] = w;
    }
}
int main()
{
    MGraph G;
    int tempi, tempj;
    CreatMGraph(&G);
    // printf("输入你所需要的边(vi,vj)上的下标i,下标j\n");
    // scanf("%d%d", &tempi, &tempj);
    // printf("权是%d\n", G.arc[tempi][tempj]);
    for (int i = 0; i < G.numVertexes; i++)
    {
        for (int j = 0; j < G.numVertexes; j++)
        {
            printf("%d ", G.arc[i][j]);
        }
        printf("\n");
    }

    return 0;
}