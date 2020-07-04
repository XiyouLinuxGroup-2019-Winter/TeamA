/*************************************************************************
	> File Name: films3.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 15时52分06秒
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include "list.h"
void showmovies(Item item);
int main()
{
    List movies;
    Item temp;
    //初始化
    IntializeList(＆movies);
    if(ListIsFull(movies))
    {
        fprintf(stderr,"no memory available! Bye!\n");
        exit(1);
    }
    //收集并存储
    puts("Enter first movie title:");
    while(fgets(temp.title,size,stdin)!=NULL && temp.title[0]!='\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d",&temp.rating);
        while(getchar()!='\n');continue;
        if(AddItem(temp,&movies)==false)
        {
            fprintf(stderr,"Promble allocating memory\n");
            break;
        }
        if(ListIsFull(movies))
        {
            puts("The list is now full:");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }

    //显示
    if(ListIsEmpty(movies))
    printf("No data entered:");
    else
    {
        printf("Here is the movie list:\n");
        Traverse(movies,showmovies);
    }
    printf("You entered %d movies.\n",ListItemCount(movies));

    //清除
    EmptyTheList(&movies);
    printf("Bye!\n");
}

void showmovies(Item item)
{
    printf("Movie:%s Rating :%d\n",item.title.item.rating);
}
