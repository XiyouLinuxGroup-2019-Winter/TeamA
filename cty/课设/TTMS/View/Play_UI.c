#include<stdio.h>
#include<stdlib.h>
#include "Play_UI.h"
#include "Schedule_UI.h"
#include "../Service/Play.h"
#include "../Common/common.h"
#include "../Common/List.h"
#include "../Service/Account.h"

/* ��Ŀ���������� */
char pchoice;
void Play_UI_MgtEntry(void) {
    Pagination_t paging;
    paging.offset = 0;
    paging.pageSize = 5;
    int id, i;
    play_list_t list, f;

    play_node_t *p;
    List_Init(list, play_node_t);
    list->next = NULL;
    paging.totalRecords = Play_Srv_FetchAll(list);
        Paging_Locate_FirstPage(list, paging);
    do {

        system("cls");
        printf("user: %s | id: %d \n", gl_CurUser.username, gl_CurUser.id);
        play_t buf;
        /* �����Ŀ��Ϣ���˵��� ���ݿգ�*/
        printf("\n====================================\n");
        printf("           Play information         \n");
        Paging_ViewPage_ForEach(list, paging, play_node_t, p, i) {
            if (p == NULL) {
                break;
            }
            printf("====================================\n");
            printf("ID:                      %d         \n", p->data.id);
            printf("name:                    %s         \n", p->data.name);
            printf("area:                    %s         \n", p->data.area);
            printf("duration:                %d         \n", p->data.duration);
            if (p->data.type == 1)
                printf("type:                    %s         \n", "film");
            else if (p->data.type == 2)
                printf("type:                    %s         \n", "opear");
            else
                printf("type:                    %s         \n", "concert");
            if (p->data.rating == 1)
                printf("rating:                  %s         \n", "child");
            else if (p->data.rating == 2)
                printf("rating:                  %s         \n", "teenage");
            else
                printf("rating:                  %s         \n", "adult");
            printf("Show start date:         %d-%d-%d   \n", p->data.start_date.year, p->data.start_date.month,
                   p->data.start_date.day);
            printf("End show time:           %d-%d-%d   \n", p->data.end_date.year, p->data.end_date.month,
                   p->data.end_date.day);
            printf("Suggested fare:          %d         \n", p->data.price);
            printf("====================================\n");
        }
//        while(list->next != NULL) {
//            f = list;
//            list = list->next;
//            free(f);
//        }
        printf("-------Total Records:%2d------------------------------Page%2d/%2d-------------------\n",
               paging.totalRecords, Pageing_CurPage(paging), Pageing_TotalPages(paging));
        printf("====================================================================================\n");
        printf("                                                                                    \n");
        printf("[s]Query the play    [a]Add a play       [u]Modify the play        [d]Delete a play \n");
        printf("[p]last page                      [r]return                        [n]next page     \n");
        printf("====================================================================================\n");
        printf("Please input your choice:");
        scanf("%c", &pchoice);
        getchar();
        if (pchoice == 's' || pchoice == 'S') {
            printf("please input ID:");
            scanf("%d", &id);
            getchar();
            if (Plat_UI_Query(id)) {
                printf("do you want to move to the Schedule UI?(y or n):");
                scanf("%c", &pchoice);
                getchar();
                if (pchoice == 'y') {
                    Schedule_UI_MgtEntry(id);
                }
            } else {
                printf("Play does not exist\n");
            }
            Play_UI_MgtEntry();
        } else if (pchoice == 'a' || pchoice == 'A') {
            Play_UI_Add();
            Play_UI_MgtEntry();
        } else if (pchoice == 'u' || pchoice == 'U') {
            printf("please input ID:");
            scanf("%d", &id);
            Play_UI_Modify(id);
            paging.totalRecords = Play_Srv_FetchAll(list);
            Play_UI_MgtEntry();

        } else if (pchoice == 'd' || pchoice == 'D') {
            printf("please input ID:");
            scanf("%d", &id);
            getchar();
            Play_UI_DeleteByID(id);
            paging.totalRecords = Play_Srv_FetchAll(list);
            Play_UI_MgtEntry();

        } else if (pchoice == 'p' || pchoice == 'P') {
            if (!Pageing_IsFirstPage(paging)) {
                Paging_Locate_OffsetPage(list, paging, -1, play_node_t);
                paging.totalRecords = Play_Srv_FetchAll(list);
            }
        } else if (pchoice == 'n' || pchoice == 'N') {
            if (!Pageing_IsLastPage(paging)) {
                Paging_Locate_OffsetPage(list, paging, 1, play_node_t);
                paging.totalRecords = Play_Srv_FetchAll(list);
            }
        }

    }while (pchoice != 'r' && pchoice != 'R');

}

/* ��Ӿ�Ŀ */
int Play_UI_Add(void) {
    char flag;
    int newCount = 0;
    while(1) {
        play_t data;
        printf("Please enter the title of the play:");
        scanf("%s", data.name);
        printf("Please enter the stage level:");
        scanf("%d", &data.rating);
        printf("Please enter the type of play:");
        scanf("%d", &data.type);
        printf("Please enter the production area:");
        scanf("%s", data.area);
        printf("Please enter the play duration:");
        scanf("%d", &data.duration);
        printf("Please enter the show start date:");
        scanf("%d %d %d", &data.start_date.year, &data.start_date.month, &data.start_date.day);
        printf("Please enter the end of play date:");
        scanf("%d %d %d", &data.end_date.year, &data.end_date.month, &data.end_date.day);
        printf("Please enter the recommended fare:");
        scanf("%d", &data.price);
        getchar();
        Play_Srv_Add(&data);
        newCount++;
        printf("Add more?([a] to add, others to return)\n");
        scanf("%c", &flag);
        getchar();
        if(flag != 'a' && flag != 'A') {
            return newCount;
        }
    }
}

/* ��ѯ��Ŀ */
int Plat_UI_Query(int id) {
    int rtn = 0;
    play_t data;
    if(Play_Srv_FetchByID(id, &data)) {
        printf("Search succeeded!\n");
        printf("=============================\n");
        printf("       Play information      \n");
        printf("=============================\n");
        printf("name:             %s         \n", data.name);
        printf("area:             %s         \n", data.area);
        printf("duration:         %d         \n", data.duration);
        if(data.type == 1)
            printf("type:             %s         \n", "film");
        else if(data.type == 2)
            printf("type:             %s         \n", "opear");
        else
            printf("type:             %s         \n", "concert");
        if(data.rating == 1)
            printf("rating:           %s         \n", "child");
        else if(data.rating == 2)
            printf("rating:           %s         \n", "teenage");
        else
            printf("rating:           %s         \n", "adult");
        printf("Show start date:  %d-%d-%d   \n", data.start_date.year, data.start_date.month, data.start_date.day);
        printf("End show time:    %d-%d-%d   \n", data.end_date.year, data.end_date.month, data.end_date.day);
        printf("Suggested fare:   %d         \n", data.price);
        printf("=============================\n");
        rtn = 1;
        return rtn;
    }
    else {
        printf("Query failed\n");
    }

}

int Play_UI_Modify(int id) {
    int rtn = 0;
    play_t data;
    if(Play_Srv_FetchByID(id, &data)) {
        printf("=============================\n");
        printf("       Play information      \n");
        printf("=============================\n");
        printf("name:             %s         \n", data.name);
        printf("area:             %s         \n", data.area);
        printf("duration:         %d         \n", data.duration);
        if(data.type == 1)
            printf("type:             %s         \n", "film");
        else if(data.type == 2)
            printf("type:             %s         \n", "opear");
        else
            printf("type:             %s         \n", "concert");
        if(data.rating == 1)
            printf("rating:           %s         \n", "child");
        else if(data.rating == 2)
            printf("rating:           %s         \n", "teenage");
        else
            printf("rating:           %s         \n", "adult");
        printf("Show start date:  %d-%d-%d   \n", data.start_date.year, data.start_date.month, data.start_date.day);
        printf("End show time:    %d-%d-%d   \n", data.end_date.year, data.end_date.month, data.end_date.day);
        printf("Suggested fare:   %d         \n", data.price);
        printf("=============================\n");
    }
    else {
        printf("can not query!\n");
        return rtn;
    }
    printf("Please enter the play name:");
    scanf("%s", data.name);
    printf("Please enter the stage level:");
    scanf("%d", &data.rating);
    printf("Please enter the type of play:");
    scanf("%d", &data.type);
    printf("Please enter the production area:");
    scanf("%s", data.area);
    printf("Please enter the play duration:");
    scanf("%d", &data.duration);
    printf("Please enter the show start date:");
    scanf("%d %d %d", &data.start_date.year, &data.start_date.month, &data.start_date.day);
    printf("Please enter the end of play date:");
    scanf("%d %d %d", &data.end_date.year, &data.end_date.month, &data.end_date.day);
    printf("Please enter the recommended fare:");
    scanf("%d", &data.price);
    getchar();
    if(Play_Srv_Modify(&data)) {
        rtn = 1;
        printf("succses\n");
        return rtn;
    }
    else {
        printf("can not modify\n");
        return rtn;
    }

}

/* ɾ����Ŀ */
int Play_UI_DeleteByID(int id) {
    int rtn = 0;

    if(Play_Srv_DeleteByID(id)) {
        printf("succses\n");
        rtn = 1;
        return rtn;
    }
    else {
        printf("can not delete\n");
        return rtn;
    }
}
