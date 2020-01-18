#include <stdio.h>
#include <string.h>
void get_next(char P[], int next[])
{
    int j = 0, k = -1;
    next[0] = -1;
    while (j < (int)strlen(P) - 1)
    {
        if (k == -1 || P[j] == P[k])
        {
            j++;
            k++;
            next[j]=k;
        }
        else
            k=next[k];
    }
}
void get_nextval(char P[],int nextval[])
{
    int j=0,k=-1;
    nextval[0]=-1;
    while (j<(int)strlen(P)-1)
    {
        if(k==-1||P[j]==P[k])
        {
            j++;
            k++;
            if(P[j]!=P[k])
                nextval[j]=k;
            else
                nextval[j]=nextval[k];
        }
        else
            j=nextval[j];
    }
    
}
int index_kmp(char S[],char P[],int pos)
{
    // printf("%d\n",(int)strlen(P));
    int i=pos;
    int j=0;
    int next[255];
    get_next(P,next);
    
    // for(int i=0;i<6;i++)
    // printf("%d\n",next[i]);

    while (i<=(int)strlen(S)-1&&j<=(int)strlen(P)-1)
    {
        if(j==-1||S[i]==P[j])
        {
            j++;
            i++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j>(int)strlen(P)-1)
        return i+1-(int)strlen(P);
    else
        return 0;    
}
int index_kmp_nextval(char S[],char P[],int pos)
{
    // printf("%d\n",(int)strlen(P));
    int i=pos;
    int j=0;
    int nextval[255];
    get_nextval(P,nextval);
    
    // for(int i=0;i<6;i++)
    // printf("%d\n",next[i]);

    while (i<=(int)strlen(S)-1&&j<=(int)strlen(P)-1)
    {
        if(j==-1||S[i]==P[j])
        {
            j++;
            i++;
        }
        else
        {
            j=nextval[j];
        }
    }
    if(j>(int)strlen(P)-1)
        return i+1-(int)strlen(P);
    else
        return 0;    
}
int main()
{
    char S[]="ababacbaba";
    
    char P[]="acbaba";
    
    int index;
    if((index=index_kmp(S,P,0))==0)
    printf("not find");
    else
    printf("index=%d",index);
    int index2;
        if((index2=index_kmp_nextval(S,P,0))==0)
    printf("not find");
    else
    printf("index2=%d",index2);
    return 0;
}
