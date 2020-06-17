/*************************************************************************
	> File Name: PersonnelRegistrationSystem.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月06日 星期五 09时22分01秒
 ************************************************************************/
#include "PRS.h"
void sys_err(char *str)
{

}
void clear_buffer()
{
    char ch;
    while((ch=getchar())!='\n' && ch!=EOF)
        ;
}
PERSON* Create()
{
    PERSON *head=(PERSON*)malloc(sizeof(PERSON));
    if(head==NULL)
    {
        sys_err("malloc error\n");
        return NULL;
    }
    head->next=NULL;
    return head;
}
PERSON* Create_node()
{
    PERSON* node=(PERSON*)malloc(sizeof(PERSON));
    if(node==NULL)
    {
        sys_err("malloc error");
        return NULL;
    }
    node->next=NULL;

    printf("请输入来者号码：");
    while(scanf("%d",&node->num)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }
    
    printf("请输入人员姓名：");
    while(scanf("%s",node->name)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }

    printf("请输入人员年龄：");
    while(scanf("%d",node->age)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }

    printf("请输入人员手机号：");
    while(scanf("%s",node->phone)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }

    printf("请输入人员来自哪里：");
    while(scanf("%s",node->come)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }

    printf("请输入备注：");
    while(scanf("%s",node->thing)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }
    
    return node;
}
void Add_head(PERSON* head)
{
    PERSON* node=Create_node();
    PERSON* tail=head;
    
    node->next=head->next;
    head->next=node;
}

void Add_tail(PERSON* head)
{
    PERSON* node=Create_node();
    PERSON* tail=head;

    tail->next=node;
    tail=node;
    tail->next=NULL;
}
void Delete_Num(PERSON* head,int pos)
{
    PERSON* p=head;
    PERSON* t=p->next;
    if(!p)
    {
        printf("数据为空\n");
        return;
    }
    while(t!=NULL && t->num!=pos)
    {
        t=t->next;
        p=p->next;
    }
    if(t==NULL)
    {
        printf("没有找到可以删除的号码\n");
        return;
    }
    p->next=t->next;
    free(t);
    return;
}
void Delete_Name(PERSON* head,char name[])
{
    PERSON* p=head;
    PERSON* t=p->next;
    if(!p)
    {
        printf("数据为空\n");
        return;
    }
    while(t!=NULL && *t->name!=*name)
    {
        t=t->next;
        p=p->next;
    }
    if(t==NULL)
    {
        printf("没有找到可以删除的名字\n");
        return;
    }
    p->next=t->next;
    free(t);
    return;
}
void Find_Num(PERSON* head,int pos)
{
    printf("在查找，请稍等..\n");
    sleep(2000);
    PERSON* p=head->next;
    if(p==NULL)
    {
        printf("无数据\n");
        return;
    }
    while(p!=NULL && p->num!=pos)
    {
        p=p->next;
    }

    if(p==NULL)
    {
        printf("数据未找到!\n");
        return;
    }
    printf("\n号码\t姓名\t年龄\t手机号\t来自哪里\t备注\n");
    
    printf("%d\t",p->num);
    printf("%s\t",p->name);
    printf("%d\t",p->age);
    printf("%s\t",p->phone);
    printf("%s\t",p->come);
    printf("%s\n",p->thing);
       
}
void Find_Name(PERSON* head,char name[])
{
    printf("在查找，请稍等..\n");
    sleep(2000);
    PERSON* p=head->next;
    if(p==NULL)
    {
        printf("无数据\n");
        return;
    }
    while(p!=NULL && *p->name!=*name)
    {
        p=p->next;
    }

    if(p==NULL)
    {
        printf("数据未找到!\n");
        return;
    }
    printf("\n号码\t姓名\t年龄\t手机号\t来自哪里\t备注\n");
    
    printf("%d\t",p->num);
    printf("%s\t",p->name);
    printf("%d\t",p->age);
    printf("%s\t",p->phone);
    printf("%s\t",p->come);
    printf("%s\n",p->thing);
}
void Combined_Query(PERSON* head,int age,char phone[])
{
    printf("在查找，请稍等.....\n");
    sleep(2000);
    int flag=0;

    PERSON* p=head->next;
    if(p==NULL)
    {
        printf("没有此数据!\n");
        return;
    }
    printf("\n号码\t姓名\t年龄\t手机号\t来自哪里\t备注\n");
    
    while(p)
    {
        if(p->age==age)
        {
            if(strcmp(p->phone,phone)==0)
            {
                printf("%d\t",p->num);
                printf("%s\t",p->name);
                printf("%d\t",p->age);
                printf("%s\t",p->phone);
                printf("%s\t",p->come);
                printf("%s\n",p->thing);
                flag=1;
            }
        }
        p=p->next;
    }
    if(flag)
    {
        printf("\n信息已查找完成!\n");
    }
    else
    {
        printf("\n未查找到相关信息!\n");
    }
    return;
}
void Change_Num(PERSON* head,int num)
{
    PERSON* p=head->next;
    if(p==NULL)
    {
        printf("无数据！\n");
        return;
    }
    while(p!=NULL &&p->num!=num)
        p=p->next;
    if(p==NULL)
    {
        printf("无数据！\n");
        return;
    }

    printf("\n请输入修改后的号码:");
    while(scanf("%d",&p->num)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }
    
    printf("请输入修改后的姓名：");
    while(scanf("%s",p->name)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }

    printf("请输入修改后的年龄：");
    while(scanf("%d",p->age)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }

    printf("请输入修改后的手机号：");
    while(scanf("%s",p->phone)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }

    printf("请输入修改后的来源地：");
    while(scanf("%s",p->come)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }

    printf("请输入修改后的备注：");
    while(scanf("%s",p->thing)!=1)
    {
        sys_err("scanf error!");
        printf("请重新输入:");
        clear_buffer();
    }

}
void show(PERSON* head)
{
    PERSON* p=head;
    printf("\n号码\t姓名\t年龄\t手机号\t来自哪里\t备注\n");
    while(p->next)
    {
        printf("%d\t",p->next->num);
        printf("%s\t",p->next->name);
        printf("%d\t",p->next->age);
        printf("%s\t",p->next->phone);
        printf("%s\t",p->next->come);
        printf("%s\n",p->next->thing);
        p=p->next;
    }
    printf("\n");
}
void Ascending_sort(PERSON* head)
{
    PERSON* pnew=head;
    if(pnew==NULL)
    {
        printf("\n无数据!\n");
    }
    else
    {
        PERSON* p=NULL;
        PERSON* q=NULL;
        PERSON* t=NULL;
        PERSON n;
        for(p=head;p;p=p->next)
        {
            for(q=p->next;q;q=q->next)
            {
                if(strcmp(p->name,q->name)>0)//p比q大
                {
                    n=*p;
                    *p=*q;
                    *q=n;
                    t=p->next;
                    p->next=q->next;
                    q->next=t;
                }
            }
        }
        printf("\n号码\t姓名\t年龄\t手机号\t来自哪里\t备注\t");
        printf("\n-------------------------------------------\n");
        while(pnew->next)
        {
            printf("\n%d\t",pnew->next->num);
            printf("%s\t",pnew->next->name);
            printf("%d\t",pnew->next->age);
            printf("%s\t",pnew->next->phone);
            printf("%s\t",pnew->next->come);
            printf("%s\n",pnew->next->thing);
            pnew=pnew->next;
        }
    }
    
    /*
    int tnum;
    int tage;
    char tname[20];
    char tphone[50];
    char tcome[100];
    char tthing[100];
    PERSON* p=head;
    PERSON* t=head->next;
    if(p->next==NULL)
    {
        printf("\n无数据，无法排序!\n");
        return;
    }
    while(t->next)
    {
        p=p->next;
        t=t->next;
        if(p->num>t->num)
        {
            tnum=p->num;
            tage=p->age;
            strcpy(tname,p->name);
            strcpy(tphone,p->phone);
            strcpy(tcome,p->come);
            stcpy(tthing,p->thing);

            p->num=t->num;
            p->age=t->age;
            strcpy(p->name,t->name);
            strcpy(p->phone,t->phone);
            strcpy(p->come,t->come);
            stcpy(p->thing,t->thing);

            t->num=tnum;
            t->age=tage;
            strcpy(t->name,tname);
            strcpy(t->phone,tphone);
            strcpy(t->come,tcome);
            stcpy(t->thing,tthing);

            Ascending_sort(head);            
        }
    }
    */
}
void Descending_Sort(PERSON* head)
{
    PERSON* pnew=head;
    if(pnew==NULL)
    {
        printf("\n无数据!\n");
    }
    else
    {
        PERSON* p=NULL;
        PERSON* q=NULL;
        PERSON* t=NULL;
        PERSON n;
        for(p=head;p;p=p->next)
        {
            for(q=p->next;q;q=q->next)
            {
                if(p->num < q->num)
                {
                    n=*p;
                    *p=*q;
                    *q=n;
                    t=p->next;
                    p->next=q->next;
                    q->next=t;
                }
            }
        }
        printf("\n号码\t姓名\t年龄\t手机号\t来自哪里\t备注\n");
        printf("\t-------------------------------------------\n");
        while(pnew->next)
        {
            printf("\n%d\t",pnew->next->num);
            printf("%s\t",pnew->next->name);
            printf("%d\t",pnew->next->age);
            printf("%s\t",pnew->next->phone);
            printf("%s\t",pnew->next->come);
            printf("%s\n",pnew->next->thing);
            pnew=pnew->next;
        }
    }
    
    /*int tnum;
    int tage;
    char tname[20];
    char tphone[50];
    char tcome[100];
    char tthing[100];
    PERSON* p=head;
    PERSON* t=head->next;
    if(p->next==NULL)
    {
        printf("\n无数据，无法排序!\n");
        return;
    }
    while(t->next)
    {
        p=p->next;
        t=t->next;
        if(p->num<t->num)
        {
            tnum=p->num;
            tage=p->age;
            strcpy(tname,p->name);
            strcpy(tphone,p->phone);
            strcpy(tcome,p->come);
            stcpy(tthing,p->thing);

            p->num=t->num;
            p->age=t->age;
            strcpy(p->name,t->name);
            strcpy(p->phone,t->phone);
            strcpy(p->come,t->come);
            stcpy(p->thing,t->thing);

            t->num=tnum;
            t->age=tage;
            strcpy(t->name,tname);
            strcpy(t->phone,tphone);
            strcpy(t->come,tcome);
            stcpy(t->thing,tthing);

            Descending_Sort(head);            
        }
    }
    */
}
void Read_File(PERSON* head)
{
    FILE* fp;
    fp=fopen("Person.txt","r");
    if(fp==NULL)
    {
        printf("\n文件打开失败!\n");
        return;
    }
    PERSON* p=Create_node();
    while(fscanf(fp,"%d\t%s\t%d\t%s\t%s\t%s\n",&p->num,p->name,&p->age,p->phone,p->come,p->thing)!=EOF)
    {
        Add_tail(head);
    }
    printf("正在写入\n");
    sleep(1000);
    printf("写入完成!\n");
    fclose(fp);
    return;
}
void Save_File(PERSON* head)
{
    FILE* fp;
    fp=fopen("Person.txt","w");
    if(fp==NULL)
    {
        printf("\n文件打开失败!\n");
        return;
    }
    PERSON* p=head->next;
    if(p==NULL)
    {
        return;
    }
    else
    {
        while(p)
        {
            fprintf(fp,"%d\t%s\t%d\t%s\t%s\t%s\n",&p->num,p->name,&p->age,p->phone,p->come,p->thing);
            p=p->next;
        }
    }
    fclose(fp);
    printf("\n正在保存!\n");
    sleep(1000);
    printf("保存成功!\n");
    return; 
}
void Create_User_File()
{
    FILE* fp;
    if((fp=fopen("user","r"))==NULL) 
    {
        if((fp=fopen("user","w+"))==NULL)
        {
            sys_err("fopen w+ error!");
            printf("创建用户文件失败!\n");
            sleep(2000);
            return;
        }
    }
    fclose(fp);
    return;
}
void Login_Menu()
{
    printf("************************************\n");
    printf("             人员流动管理系统\n");
    printf("************************************\n");
    printf("1.登录系统\n");
    printf("2.新用户注册\n");
    printf("3.找回密码\n");
    printf("4.开发者说明\n");
    printf("0.退出系统\n");
    printf("***********************************\n");
    printf("请输入对应的数字:");
    int choice;
    while(scanf("%d", &choice)!=1||choice<0||choice>4)
    {
        clear_buffer();
        printf("\n请重新选择功能(0-4)\n");
    }

    switch (choice)
    {
    case 1:
        Enter();  //登录
        break;
    case 2:
        Login();  //注册
        break;
    case 3:
        Find_password();
        break;
    case 4:
        Developor();  //开发者说明
        Login_Menu();
        break;
    case 0:
        printf("正在退出中，请稍后...\n");
        sleep(2000);
        printf("再见!\n");
        exit(0);
    }
    //switch (choice)
    //{
      //  case 1: input_message(); break;       /*录入模块*/
        //case 2: output_message(); break;     /*输出模块*/
        //case 3: renew_message(); break;      /*更新模块*/
        //case 4: inquire_message(); break;    /*查询模块*/
        //case 5: count_message(); break;      /*统计模块*/
        //case 6: sort_message(); break;        /*排序模块*/
        //case 0: break;                                    /*退出系统*/
    //}
}
void Developor()
{
    printf("------------------------------------\n");
    printf("        >作者:bokette\n");
    printf("-------------------------------------\n");
    printf("        >邮箱:bokket@XiyouLinuxGroup\n");
    printf("        >学校:XUPT\n");
    printf("        >班级:DSBD-1902\n");
    printf("------------------------------------\n");
}
void Menu()
{
    display("           Welcome to 人员流动管理系统(TMS)!");
    printf("1.添加人员信息\n");
    printf("2.删除人员信息\n");
    printf("3.修改人员信息\n");
    printf("4.查找人员信息\n");
    printf("5.按人员号码排序\n");
    printf("6.读取人员信息\n");
    printf("7.保存人员信息\n");
    //printf("3.修改人员信息\n");
    //printf("4.查找人员信息\n");
    printf("0.退出登录\n");
    printf("------------------------------------\n");
    printf("请输入对应的数字:\n");
    int choice;
    while(scanf("%d", &choice)!=1 || choice<0 || choice>9) 
    {
        clear_buffer();
        printf("\n输入错误!请重新输入:\n");
    }

    switch(choice)
    {
        case 1:
            display("        TMS");
            printf("1.头插法录入信息\n");
            printf("2.尾插法录入信息\n");
            printf("3.指定位置录入信息\n");
            printf("0.返回上一步\n");
            printf("--------------------------------------------\n");
            printf("请输入对应的序号：");
            int i;
            while(scanf("%d", &i) != 1 || i< 0 || i> 3) 
            {
                clear_buffer();
                printf("\n输入错误！请重新输入：");
            }
            switch (i)
            {
                case 1:
                    display("         TMS");
                    Add_head(list);
                    break;
                case 2:
                    display("         TMS");
                    show(list);
                    Add_tail(list);
                    break;
                case 3:
                    display("         TMS");
                    show(head);
            AddPlayerByPos(list);
            break;
        case 0:
            return;
            break;
        }
        ShowAll(list);
        system("pause");
        break;
    case 2:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.根据球员号码删除\n");
        printf("2.根据球员姓名删除\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        while (scanf("%d", &j) != 1 || j < 0 || j > 2) {
            safe_flush(stdin);
            printf("\n输入错误！请重新输入：");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            int num;
            printf("请输入想要删除的球员的号码：");
            while (scanf("%d", &num) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            DeletePlayerByNum(list, num);
            ShowAll(list);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            ShowAll(list);
            char name[100];
            printf("请输入想要删除的球员的姓名：");
            while (scanf("%s", name) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            DeletePlayerByName(list, name);
            ShowAll(list);
            system("pause");
            break;
        case 0:
            return;
            break;
        }
        break;
    case 3:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.根据球员号码查询\n");
        printf("2.根据球员姓名查询\n");
        printf("3.根据球员位置和状态组合查询\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        while (scanf("%d", &j) != 1 || j < 0 || j > 3) {
            safe_flush(stdin);
            printf("输入错误！请重新输入：");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            int num;
            printf("请输入要查询的球员的号码：");
            while (scanf("%d", &num) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            FindPlayerByNum(list, num);
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            char name[100];
            printf("请输入要查询的球员的姓名：");
            while (scanf("%s", name) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            FindPlayerByName(list, name);
            break;
        case 3:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            char position[20];
            char remark[20];
            printf("请输入要查询的球员的位置：");
            while (scanf("%s", position) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            printf("请输入要查询的球员的状态：");
            while (scanf("%s", remark) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            CombinedQuery(list, position, remark);
            break;
        case 0:
            return;
            break;
        }
        break;
    case 4:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.根据球员号码修改\n");
        printf("2.根据球员姓名修改\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        while (scanf("%d", &j) != 1 || j < 0 || j > 2) {
            safe_flush(stdin);
            printf("\n输入错误，请重新输入：");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            int num;
            printf("请输入要修改的球员的号码：");
            while (scanf("%d", &num) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            ChangePlayerByNum(list, num);
            ShowAll(list);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            char name[100];
            printf("请输入要修改的球员的姓名：");
            while (scanf("%s", name) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            ChangePlayerByName(list, name);
            ShowAll(list);
            system("pause");
            break;
        case 0:
            return;
            break;
        }
        break;
    case 5:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.按球员号码升序排序\n");
        printf("2.按球员号码降序排序\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        while (scanf("%d", &j) != 1 || j < 0 || j > 2) {
            safe_flush(stdin);
            printf("\n输入错误，请重新输入：");
        }
        switch (j) {
        case 1:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            sorted(list);
            ShowAll(list);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            sorted_reverse(list);
            ShowAll(list);
            system("pause");
            break;
        case 0:
            return;
            break;
        }
        break;
    case 6:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        ShowAll(list);
        system("pause");
        break;
    case 7:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        load(list);
        break;
    case 8:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        save(list);
        break;
    case 9:
        system("cls");
        printf("--------------------------------------------\n");
        printf("              球员信息管理系统\n");
        printf("--------------------------------------------\n");
        printf("1.按球员位置统计数据\n");
        printf("2.按球员状态统计数据\n");
        printf("3.组合统计数据\n");
        printf("0.返回上一步\n");
        printf("--------------------------------------------\n");
        printf("请输入对应的数字：");
        while (scanf("%d", &j) != 1 || j < 0 || j > 3) {
            safe_flush(stdin);
            printf("\n输入错误，请重新输入：");
        }
        switch (j) {
        case 1:
            statistics_position(list);
            break;
        case 2:
            statistics_remark(list);
            break;
        case 3:
            system("cls");
            printf("--------------------------------------------\n");
            printf("              球员信息管理系统\n");
            printf("--------------------------------------------\n");
            char position[20];
            char remark[20];
            printf("请输入要统计的球员位置：");
            while (scanf("%s", position) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            printf("请输入要统计的球员状态：");
            while (scanf("%s", remark) != 1) {
                printf("\n输入错误！请重新输入：");
                safe_flush(stdin);
            }
            com_statistics(list, position, remark);
            break;
        case 0:
            return;
            break;
        }
        break;
    case 0:
        printf("正在退出，请稍候...\n");
        Sleep(3000);
        LoginMenu();
        break;
    }
}
}
//自定义的getch()函数
char getch()
{
	char ch;

    system("stty -echo");//不回显
    system("stty -icanon");//设置一次性读完操作，如使用getchar()读操作,不需要按回车
    ch = getchar();
    system("stty icanon");//取消上面的设置
    system("stty echo");//回显

    return ch;
}
void Hidden_password(char *password)
{
    char ch;
    int i=0;
    while((ch=getch())!='\r')//当输入不为回车时
    {
        if(ch=='\b' && i>=1)//当密码输入为空格键并且输入字符数大于１时
        {
            printf("\b");
            printf(" ");
            printf("\b");
            if(i)     //如果有字数
                i--;
            else
            {
                putchar('\a');//警报
            }
        }
        else
        {
            printf("*");
            password[i++]=ch;
        }
    }
    password[i]='\0';
    printf("\n");

    return;
}
void Enter()
{
    user old,new;
    FILE* fp;
    char temp[MAX];
    /*printf("------------------------------------\n");
    printf("         Welcome to 人员流动管理系统(TMS)\n");
    printf("------------------------------------\n");*/
    display("    请登入\n");

    if((fp=fopen("user","r"))==NULL)
    {
        sys_err("fopen error!\n");
        printf("登录失败！\n");
        return;
    }
    //fread(&old,sizeof(user),1,fp);
    puts("请输入账号:\n");
    while(scanf("%s",new.id)!=1)
    {
        printf("用户名错误!\n");
        clear_buffer();
    }
    while(!feof(fp))
    {
        fread(&old,sizeof(user),1,fp);
        if(strcmp(new.id,old.id)==0)
        {
            puts("请输入密码:");
            Hidden_password(temp);
            if(strcmp(temp,old.password)==0)
            {
                fclose(fp);
                printf("\n登录成功!\n");
                sleep(200);
                PERSON* head=Create_node();
                while(1)
                    Menu();
                return;
            }
            else
            {
                puts("密码错误!\n");
                sleep(200);
                Login_Menu();
            }
        }
        else
        {
            printf("账号不存在!\n");
            fclose(fp);
            sleep(200);
            Login_Menu();
            return;
        }
        
    }
    /*while(1)
    {
        if(strcmp(new.id,old.id)==0)
            break;
        else
        {
            if(!feof(fp))
            {
                fread(&old,sizeof(user),1,fp);
            }
            else
            {
                printf("用户名不存在!\n");
                fclose(fp);
                menu();
                return;
            }
            
        }
    }*/
}

void display(char* str)
{
    int i;
    for(i=0;i<50;i++)
        putchar("-");
    putchar("\n");
    printf("       %s\n",str);
    for(i=0;i<50;i++)
        putchar("-");
    putchar('\n');
    return;
}
void Login()
{
    FILE *fp;
    user old,new;
    char temp[MAX];
    display("      注册账号");
    if((fp=fopen("user","r"))==NULL)
    {
        sys_err("fopen error!\n");
        printf("读取失败！\n");
        return;
    }
    fread(&old,sizeof(struct user),1,fp);    
    puts("请输入账号:");
    while(scanf("%s",new.id)!=1) 
    {
        printf("账号错误!\n");
        clear_buffer();
    }
    while(1)
    {
        if(strcmp(new.id,old.id)==0)
        {
            printf("\n账号重复!\n");
            fclose(fp);
            sleep(200);
            Login_Menu();
            return;
        }
        else
        {
            if(!feof(fp))
                fread(&old,sizeof(struct user),1,fp);    
            else
                break;
        }
    }
    puts("请输入密码:");
    Hidden_password(new.password);
    puts("请确认密码:");
    Hidden_password(temp);
    while(1)
    {
        if(strcmp(new.password,temp)==0)
        {
            puts("请输入电话号码:");
            new.telephonenum=Get_Num();
            fp=fopen("user","a");
            fwrite(&new,sizeof(user),1,fp);
            printf("\n账号%s注册成功!\n",new.id);
            fclose(fp);
            sleep(200);
            Login_Menu();
            return;
        }
        else
        {
            puts("密码不一致!\n");
            puts("请重新输入密码:");
            Hidden_password(new.password);
            puts("请再次确定密码:");
            Hidden_password(temp);
        }
    }
}
long long int Get_Num()
{
    long long int num;
    char ch;

	while(scanf("%lld",&num)!=1) 
	{
		printf("\n请重新输入\n");
        clear_buffer();
	}
	return num;
}
void Find_password()
{
    FILE *fp;
    user old;
    char temp[MAX];
    long long int num;

    display("    找回密码:");

    if((fp=fopen("user","r"))==NULL)
    {
        sys_err("fopen error!\n");
        printf("登录失败！\n");
        return;
    }
    puts("请输入账号:");
    while(scanf("%s",temp)!=1)
    {
        printf("账号错误!\n");
        clear_buffer();
    }
    while(!feof(fp))
    {
        fread(&old,sizeof(user),1,fp);
        if(strcmp(temp,old.id)==0)
        {
            puts("请输入电话号码:");
            if((num=Get_Num())==old.telephonenum)
            {
                printf("找回的密码是:%s\n",old.password);
                fclose(fp);
                sleep(200);
                Login_Menu();
                return;
            }
            else
            {
                printf("电话号码错误\n");
                sleep(200);
                Login_Menu();
            }
        }
        else
        {
            printf("账号%s不存在:\n",temp);
            fclose(fp);
            sleep(200);
            Login_Menu();
        }
    }
}


int main()
{
    

}

