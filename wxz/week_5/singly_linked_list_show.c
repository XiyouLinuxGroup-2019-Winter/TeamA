/*************************************************************************
	> File Name: sigly_linked_list_show.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月19日 星期三 03时38分45秒
 ************************************************************************/

#include<stdio.h>
#include "singly_linked_list.h"
int main()
{
    Node* head=NULL;
    Node* p=NULL;
    int choice;
    printf("学生信息\n");
    do
    {
        printf("1:输入信息\n");
        printf("2:增加信息\n");
        printf("3:删除信息\n");
        printf("4:销毁信息\n");
        printf("5:显示信息\n");
        printf("6:查找信息\n");
        printf("0:退出程序\n");
        printf("请输入：");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                head = Input(head);
                break;
            case 2:
                printf("请先确定要插入的位置学号（前插入）是否存在\n");
                printf("注意：若不存在，默认插入到最后\n");
                p = Find(head);
                Add(p);
                break;
            case 3:
                printf("请先确定要删除的学号是否存在\n");
                p = Find(head);
                Delete(p);
                break;
            case 4:Ruin(p);
                break;
            case 5:Print(p);
                break;
            case 6:Find(p);
                break;
        }
    }while(choice != 0);
}
