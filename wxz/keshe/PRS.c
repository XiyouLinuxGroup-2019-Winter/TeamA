/*************************************************************************
	> File Name: PersonnelRegistrationSystem.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月06日 星期五 09时22分01秒
 ************************************************************************/
#include "PRS.h"
int main()
{
    Login_Menu();
}
void sys_err(char *str)
{
    perror(str);
    exit(1);
}
void clear_buffer()
{
    char ch;
    while((ch=getchar())!='\n' && ch!=EOF)
        ;
}
/*PERSON* Create()
{
    PERSON *head=(PERSON*)malloc(sizeof(PERSON));
    if(head==NULL)
    {
        sys_err("malloc error\n");
        return NULL;
    }
    head->next=NULL;
    return head;
}*/
PERSON* Create()
{
    PERSON* head=(PERSON*)malloc(sizeof(PERSON));
    if (!head) 
    {
        printf("申请内存失败\n");
        return NULL;
    }
    head->next = NULL;
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

    while(tail->next!=NULL)
    {
        if(tail->next->num==node->num)
        {
            printf("\n号码重复！\n");
            return;
        }
        tail=tail->next;
    }
    
    node->next=head->next;
    head->next=node;
}

void Add_tail(PERSON* head)
{
    PERSON* node=Create_node();
    PERSON* tail=head;

    while(tail->next!=NULL)
    {
        if(tail->next->num==node->num)
        {
            printf("\n号码重复!\n");
            return;
        }
        tail=tail->next;
    }
    tail->next=node;
    node->next=NULL;
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
    sleep(5);
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
    sleep(5);
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
    sleep(5);
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
TNode* Read_File(TNode* head)
{
    FILE* fp;
    fp=fopen("Person","r");
    if(fp==NULL)
    {
        printf("\n文件打开失败!\n");
        return;
    }
    TNode* pnew=(TNode*)malloc(sizeof(TNode));

    while(fscanf(fp,"%d\t%s\t%d\t%s\t%s\t%s\n",&p->per.num,p->per.name,&p->per.age,p->per.phone,p->per.come,p->per.thing)!=EOF)
    {
        head->next=p;
        head=head->next;
        p=Create();
    }
    printf("正在写入\n");
    sleep(5);
    printf("写入完成!\n");
    fclose(fp);
}
void Save_File(PERSON* head)
{
    FILE* fp;
    fp=fopen("person","w");
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
            //fprintf(fp,"%d\t%s\t%d\t%s\t%s\t%s\n",&p->num,p->name,&p->age,p->phone,p->come,p->thing);
            fwrite(&p,sizeof(PERSON),1,fp);
            p=p->next;
        }
    }
    fclose(fp);
    printf("\n正在保存!\n");
    sleep(5);
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
            sleep(3);
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
    //Create_User_File();
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
        sleep(2);
        printf("再见!\n");
        exit(0);
    }
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
    while((ch=getch())!='\n')//当输入不为回车时
    {
        if(ch=='\b'&&i>=1)//当密码输入为空格键并且输入字符数大于１时
        {
            putchar('\b');
            putchar(' ');
            putchar('\b');
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
/*void Hidden_password(char *password)
{
    password=getpass("请输入");
    //printf("%s",password);
}*/
void Enter()
{
    user old,new;
    FILE* fp;
    char temp[MAX];
    /*printf("------------------------------------\n");
    printf("         Welcome to 人员流动管理系统(TMS)\n");
    printf("------------------------------------\n");*/
    display("请登入\n");

    if((fp=fopen("user","r"))==NULL)
    {
        sys_err("fopen error!\n");
        printf("登录失败！\n");
        return;
    }
    //fread(&old,sizeof(user),1,fp);
    puts("请输入账号:");
    while(scanf("%s",temp)!=1)
    {
        printf("账号错误!\n");
        clear_buffer();
    }
    //scanf("%s",temp);
    //fgets(temp,MAX,stdin);
    getchar();
    while(!feof(fp))
    {
        fread(&old,sizeof(user),1,fp);
        if(strcmp(temp,old.id)==0)
        {
            puts("请输入密码:");
            Hidden_password(temp);
            if(strcmp(temp,old.password)==0)
            {
                printf("\n登录成功!\n");
                sleep(5);
                //Menu(head);
                while(1)
                    Menu();
                return;
            }
            else
            {
                puts("密码错误!\n");
                sleep(3);
                //return;
                Login_Menu();
            }
        }
        else
        {
            printf("账号%s不存在!\n",temp);
            fclose(fp);
            sleep(3);
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
    system("clear");
    for(i=0;i<50;i++)
        putchar('-');
    putchar('\n');
    printf("       %s\n",str);
    for(i=0;i<50;i++)
        putchar('-');
    putchar('\n');
    return;
}
void Login()
{
    FILE *fp;
    user old,new;
    char temp[MAX];
    display("注册账号");
    if((fp=fopen("user","r"))==NULL)
    {
        sys_err("fopen error!\n");
        printf("读取失败！\n");
        return;
    }
    puts("请输入账号:");
    while(scanf("%s",new.id)!=1) 
    {
        printf("账号错误!\n");
        clear_buffer();
    }
    //scanf("%s",new.id);
    getchar();
    //s_gets(new.id,MAX);
    //fgets(new.id,MAX,stdin);
    while(fread(&old,sizeof(struct user),1,fp))
    {
        if(strcmp(new.id,old.id)==0)
        {
            printf("\n账号重复!\n");
            fclose(fp);
            sleep(5);
            Login_Menu();
            return;
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
            sleep(3);
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

    display("找回密码:");

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
    getchar();
    //fgets(temp,MAX,stdin);
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
                sleep(2);
                Login_Menu();
                //return;
            }
            else
            {
                printf("电话号码错误\n");
                sleep(3);
                Login_Menu();
            }
        }
        else
        {
            printf("账号%s不存在:\n",temp);
            fclose(fp);
            sleep(3);
            Login_Menu();
            return;
        }
    }
}

void Menu()
{
    display("           Welcome to 人员流动管理系统(TMS)!");
    printf("1.添加人员信息\n");
    printf("2.删除人员信息\n");
    printf("3.修改人员信息\n");
    printf("4.查找人员信息\n");
    printf("5.人员排序\n");
    printf("6.打印所有人员信息\n");
    printf("7.读取人员信息\n");
    printf("8.保存人员信息\n");
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

    PERSON* head;

    Create_Person_File();
    head=Create();
    switch(choice)
    {
        case 1:
            display("        TMS");
            printf("1.头插法录入信息\n");
            printf("2.尾插法录入信息\n");
            printf("0.返回上一步\n");
            printf("--------------------------------------------\n");
            printf("请输入对应的序号：");
            int i;
            while(scanf("%d", &i) != 1 || i<0 || i>2) 
            {
                clear_buffer();
                printf("\n输入错误！请重新输入：");
            }
            switch (i)
            {
                case 1:
                    display("         TMS");
                    Add_head(head);
                    break;
                case 2:
                    display("         TMS");
                    //show(head);
                    Add_tail(head);
                    break;
                case 0:
                    return;
                    break;
            }
            show(head);
            break;
        case 2:
            display("        TMS");
            printf("1.根据人员号码删除\n");
            printf("2.根据人员姓名删除\n");
            printf("0.返回上一步\n");
            printf("--------------------------------------------\n");
            printf("请输入对应的序号：");
            //int i;
            while (scanf("%d", &i) !=1 || i<0 || i>2)
            {
                clear_buffer();
                printf("\n输入错误！请重新输入:\n");
            }
            switch (i) 
            {
                case 1:
                    display("        TMS");
                    show(head);
                    int num;
                    printf("请输入想要删除的人员号码：");
                    while(scanf("%d",&num)!=1) 
                    {
                        printf("\n输入错误！请重新输入：");
                        clear_buffer();
                    }
                    Delete_Num(head, num);
                    show(head);
                    break;
                case 2:
                    display("        TMS");
                    show(head);
                    char name[100];
                    printf("请输入想要删除的人员姓名：");
                    while (scanf("%s", name) != 1)
                    {
                        printf("\n输入错误！请重新输入：");
                        clear_buffer();
                    }
                    Delete_Name(head, name);
                    show(head);
                    break;
                case 0:
                    return;
                    break;
            }
            break;
        case 3:
            display("        TMS");
            printf("1.根据人员号码修改\n");
            printf("0.返回上一步\n");
            printf("--------------------------------------------\n");
            printf("请输入对应的数字：");
            //int i;
            while(scanf("%d", &i) !=1 || i<0 || i>1) 
            {
                clear_buffer();
                printf("\n输入错误，请重新输入：");
            }
            switch (i) 
            {
                case 1:
                    display("        TMS");
                    int num;
                    printf("请输入要修改的人员号码：");
                    while (scanf("%d", &num) !=1)
                    {
                        printf("\n输入错误！请重新输入：");
                        clear_buffer();
                    }
                    Change_Num(head,num);
                    show(head);
                    break;
                case 0:
                    return;
                    break;
            }
            break;
        case 4:
            display("        TMS");
            printf("1.根据人员号码查询\n");
            printf("2.根据人员姓名查询\n");
            printf("3.根据年龄和电话组合查询\n");
            printf("0.返回上一步\n");
            printf("--------------------------------------------\n");
            printf("请输入对应的数字：");
            //int i;
            while (scanf("%d", &i) !=1 || i<0 || i>3)
            {
                clear_buffer();
                printf("输入错误！请重新输入：");
            }
            switch (i) 
            {
                case 1:
                    display("        TMS");
                    int num;
                    printf("请输入要查询的人员号码：");
                    while (scanf("%d", &num) != 1) 
                    {
                        printf("\n输入错误！请重新输入：");
                        clear_buffer();
                    }
                    Find_Num(head, num);
                    break;
                case 2:
                    display("        TMS");
                    char name[100];
                    printf("请输入要查询的人员的姓名：");
                    while (scanf("%s", name) != 1)
                    {
                        printf("\n输入错误！请重新输入：");
                        clear_buffer();
                    }
                    Find_Name(head,name);
                    break;
                case 3:
                    display("        TMS");
                    int age;
                    char thing[100];
                    printf("请输入要查询的人员年龄：");
                    while (scanf("%s",age) != 1)
                    {
                        printf("\n输入错误！请重新输入：");
                        clear_buffer();
                    }
                    printf("请输入要查询的人员备注高危等级：");
                    while (scanf("%s",thing) != 1) 
                    {
                        printf("\n输入错误！请重新输入：");
                        clear_buffer();
                    }
                    Combined_Query(head,age,thing);
                    break;
                case 0:
                    return;
                    break;
            }
            break;
        case 5:
            display("        TMS");
            printf("1.按人员姓名字母大小升序排序\n");
            printf("2.按人员号码降序排序\n");
            printf("0.返回上一步\n");
            printf("--------------------------------------------\n");
            printf("请输入对应的数字：");
            //int i;
            while (scanf("%d", &i) != 1 || i<0 || i>2) 
            {
                clear_buffer();
                printf("\n输入错误，请重新输入：");
            }
            switch (i) 
            {
                case 1:
                    display("        TMS");
                    Ascending_sort(head);
                    show(head);
                    break;
                case 2:
                    display("        TMS");
                    Descending_Sort(head);
                    show(head);
                    break;
                case 0:
                    return;
                    break;
            }
            break;
        case 6:
            display("        TMS");
            show(head);
            break;
        case 7:
            display("        TMS");
            Read_File(head);
            break;
        case 8:
            display("        TMS");
            Save_File(head);
            break;
        case 0:
            printf("正在退出,请勿强制关闭....\n");
            sleep(2);
            Login_Menu();
            break;
    }
}
