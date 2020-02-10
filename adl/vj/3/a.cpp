#include<iostream>
using namespace std;
int map[5][5];
int book[5][5];
struct node{
    int x,y,pre;
}Queue[100];
int head=0,rear=1;
int nextt[4][2]={{0,1},{1,0},{0,-1},{0,1}};
void retrack(int i)
{
    if(Queue[i].pre!=-1)
    {
        retrack(Queue[i].pre);
        cout<<"("<<Queue[i].x<<", "<<Queue[i].y<<")"<<endl;
    }
}
bool judge(int x,int y)
{
    if(x>4||y>4||x<0||y<0||(map[x][y]==1))
        return false;
    return true;
}
void bfs(int x,int y)
{
    Queue[head].x=x;
    Queue[head].y=y;
    Queue[head].pre=-1;
    while (head<rear)
    {
        for (int  j = 0; j < 4; j++)
        {
            int nextx=Queue[head].x+nextt[j][0];
            int nexty=Queue[head].y+nextt[j][1];
            if(!judge(nextx,nexty)||(book[nextx][nexty]==1))
                continue;
            book[nextx][nexty]=1;
            Queue[rear].x=nextx;
            Queue[rear].y=nexty;
            Queue[rear].pre=head;
            
            if(nextx==4&&nexty==4)
            {   retrack(rear);return ;}
                rear++;
        }
        head++;
    }
}
int main()
{
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>map[i][j];
        }
    }
    cout<<"(0, 0)"<<endl;
    bfs(0,0);

}