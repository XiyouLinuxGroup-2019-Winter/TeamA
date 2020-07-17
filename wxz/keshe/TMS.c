#include "TMS.h"
int main()
{
    Login_Menu();
    Any_Key_Continue();
    printf("谢谢使用\n");
}
void sys_err(char *str)
{
    perror(str);
    exit(1);
}
void clear_buffer()
{
    char ch;
    while (getchar() != '\n')
		continue;
    /*while((ch=getchar())!='\n' && ch!=EOF)
            continue;*/
}
TNode* Create()
{
    TNode* head=NULL;
    FILE* fp;
    Node temp;
    if((fp=fopen("Person","r"))==NULL)
	{
		sys_err("open error!");
		//Free_Node(&head);
		sleep(3);
		return NULL;
	}
    while(fread(&temp,sizeof(Node),1,fp)==1)
    {
        TNode* p;
        TNode* t=head;
        if((p=(TNode*)malloc(sizeof(TNode)))==NULL)
		{
			sys_err("malloc error");
			Free_Node(&head);
			sleep(3);
			return NULL;
		}
		p->next=NULL;
        p->per.num=temp.num;
        strcpy(p->per.name,temp.name);
        p->per.age=temp.age;
        strcpy(p->per.phone,temp.phone);
        strcpy(p->per.come,temp.come);
        strcpy(p->per.thing,temp.thing);
        if(t!=NULL)
        {
            while(t->next!=NULL)
                t=t->next;
            t->next=p;
        }
        else
        {
            head=p;
        }
    }
    fclose(fp);
    return head;
}
void Free_Node(TNode** head)
{
    TNode *t;
    TNode** p=head;
    while(*head!=NULL)
    {
        t=*head;
        *head=(*head)->next;
        free(t);
    }
    *p=NULL;
    return;
}
void Add_Tail(TNode** head)
{
    TNode* p;
    TNode* t=*head;
    if((p=(TNode*)malloc(sizeof(TNode)))==NULL)
	{
		sys_err("malloc error");
		sleep(3);
		return;
	}
    printf("请输入来者号码：");
    p->per.num=Get_int();

    printf("请输入人员姓名：");
    Get_string(p->per.name,20);

    printf("请输入人员年龄：");
    p->per.age=Get_int();

    printf("请输入人员手机号：");
    Get_string(p->per.phone,50);

    printf("请输入人员来自哪里：");
    Get_string(p->per.come,100);

    printf("请输入备注：");
    Get_string(p->per.thing,100);


    p->next=NULL;

    if(*head!=NULL)
	{
		while(t->next!=NULL) 
			t=t->next;
		t->next=p;
	}
	else
		*head=p;
	display("       录入成功!");
    sleep(3);
    
    return;
}
TNode* Find_Delete_Num(TNode* head,int num)
{
    TNode* p=head;
    while(p && p->per.num!=num)
        p=p->next;
    return p;
}
TNode* Delete_Num(TNode* head,int num)
{
    TNode* new=Find_Delete_Num(head,num);
    TNode* p;
    TNode* t;
    p=head;
    t=p; 
    if(p==NULL)
    {
        puts("没有找到人员信息,请先添加");
        return head;
    }
    if(new)
    {
    while(p)
    {
        if(p->per.num==num)
        {
            if(head==p)
            {
                head=p->next;
                //free(p);
                display("  删除成功");
                return head;
            }
            t->next=p->next;
            free(p);
            display("    删除成功!");
            sleep(3);
            return head;
        }
        t=p;
        p=p->next;
    }
    }
    display("没有找到可以删除的号码");
    return head;
}
void Delete_Name(TNode* head)
{
    TNode* p=head;
    TNode* t=NULL;
    char pname[MAX];
    puts("请输入要删除的名字:");
    scanf("%s",pname);
    int flag=0;
    while(p)
    {
        if(strcmp(pname,p->per.name)==0)
        {
            t->next=p->next;
            free(p);
            p=NULL;
            display("    删除成功!");
            flag=1;
            sleep(3);
            return;
        }
        t=p;
        p=p->next;
    }
    if(!flag)
    {
        puts("没有找到可以删除的姓名\n");
    }
    Any_Key_Continue();
    return;
}
void Change_Num(TNode* head)
{
    TNode *p=head;
    int flag=0;
    display("     修改人员信息");
    int pnum;
    puts("请输入要修改的号码:");
    pnum=Get_int();
 

    while(p)
    {
        if(pnum==p->per.num)
        {
            display("修改中");
            flag=1;
            printf("请输入修改后的号码:\n");
            p->per.num=Get_int();

            printf("请输入修改后的姓名：\n");
            Get_string(p->per.name,20);

            printf("请输入修改后的年龄：\n");
            p->per.age=Get_int();

            printf("请输入修改后的手机号：\n");
            Get_string(p->per.phone,50);

            printf("请输入修改后的来源地：\n");
            Get_string(p->per.come,100);

            printf("请输入修改后的备注：\n");
            Get_string(p->per.thing,100);
            
            Format();
            puts("修改完成");
            Format();
        }
        p=p->next;
    }
    if(!flag)
    {
        display("未查找到相关信息!\n");
    }
    Any_Key_Continue();
    return;

}
void Find_Num(TNode* head)
{
    TNode* p=head;
    int pnum;
    int flag=0;
    puts("请输入要查找的号码:");
    pnum=Get_int();
    while(p)
    {
        if(p->per.num==pnum)
        {
            display("查找成功!");
            flag=1;
            Format();

            printf("\n号码\t姓名\t年龄\t手机号\t\t来自哪里\t备注\n");
    
            printf("%d\t",p->per.num);
            printf("%s\t",p->per.name);
            printf("%d\t",p->per.age);
            printf("%s\t",p->per.phone);
            printf("%s\t\t",p->per.come);
            printf("%s\n",p->per.thing);

            Format();
        }

        p=p->next;
    }

    if(!flag)
    {
        display("未找到符合的号码");
    }
    Any_Key_Continue();
    return;
}
void Find_Name(TNode* head)
{
    TNode* p=head;
    int flag=0;
    char pname[MAX];
    puts("请输入要查找的人员:");
    Get_string(pname,MAX);
    while(p)
    {
        if(strcmp(pname,p->per.name)==0)
        {
            display("查找成功!");
            flag=1;
            Format();

            printf("\n号码\t姓名\t年龄\t手机号\t来自哪里\t备注\n");
    
            printf("%d\t",p->per.num);
            printf("%s\t",p->per.name);
            printf("%d\t",p->per.age);
            printf("%s\t",p->per.phone);
            printf("%s\t\t",p->per.come);
            printf("%s\n",p->per.thing);

            Format();
        }
        p=p->next;
    }
    if(!flag)
    {
        display("未找到符号的名字");
    }
    Any_Key_Continue();
    return;
}
void Combined_Query(TNode* head)
{
    TNode* p=head;
    int flag=0;
    char pphone[MAX];
    int page;
    puts("请输入要查找的年龄:");
    page=Get_int();
   
    puts("请输入要查找的电话:");
    Get_string(pphone,MAX);

    while(p)
    {
        if(page==p->per.age)
        {
            if(strcmp(pphone,p->per.phone)==0)
            {
                display("查找成功!");
                flag=1;
                Format();

                printf("\n号码\t姓名\t年龄\t手机号\t来自哪里\t备注\n");
        
                printf("%d\t",p->per.num);
                printf("%s\t",p->per.name);
                printf("%d\t",p->per.age);
                printf("%s\t",p->per.phone);
                printf("%s\t\t",p->per.come);
                printf("%s\n",p->per.thing);

                Format();
            }
        }
        p=p->next;
    }
    if(!flag)
    {
        display("未查找到相关信息!\n");
    }
    Any_Key_Continue();
    return;
}
void Read_File_Show(TNode* head)
{
    TNode* p=head;
    while(p)
    {
        printf("\n号码\t姓名\t年龄\t手机号\t\t来自哪里\t备注\n");
        printf("%d\t",p->per.num);
        printf("%s\t",p->per.name);
        printf("%d\t",p->per.age);
        printf("%s\t",p->per.phone);
        printf("%s\t\t",p->per.come);
        printf("%s\n",p->per.thing);
        p=p->next;
        Format();
    }
    return;
}
void Show(TNode* head)
{
    TNode* p=head;
    display("        打印人员信息");
    while(p)
    {
        printf("\n号码\t姓名\t年龄\t手机号\t\t来自哪里\t备注\n");
        printf("%d\t",p->per.num);
        printf("%s\t",p->per.name);
        printf("%d\t",p->per.age);
        printf("%s\t",p->per.phone);
        printf("%s\t\t",p->per.come);
        printf("%s\n",p->per.thing);
        p=p->next;
        Format();
    }
    Any_Key_Continue();
    return;
}
TNode* Find_Min_Num(TNode* head)
{
    TNode* pmin=head;
    TNode* p=head->next;
    while(p)
	{
		if(p->per.num<pmin->per.num)
			pmin=p;
		p=p->next;
	}
    return pmin;
}
TNode* Find_Max_Num(TNode* head)
{
    TNode* pmax=head;
    TNode* p=head->next;
    while(p)
	{
		if(p->per.num>pmax->per.num)
			pmax=p;
		p=p->next;
	}
    return pmax;
}
void Ascending_Sort(TNode* head)
{
    display("　　　　　人员号码升序");
    int tnum;
    int tage;
    char tname[20];
    char tphone[50];
    char tcome[100];
    char tthing[100];
    TNode* p=head;
    TNode* pmin;
    if(p->next==NULL)
    {
        printf("\n无数据，无法排序!\n");
        return;
    }
    while(p)
    {
        pmin=Find_Min_Num(p);
        if(strcmp(pmin->per.name,p->per.name))
        {
            tnum=pmin->per.num;
            tage=pmin->per.age;
            strcpy(tname,pmin->per.name);
            strcpy(tphone,pmin->per.phone);
            strcpy(tcome,pmin->per.come);
            strcpy(tthing,pmin->per.thing);

            pmin->per.num=p->per.num;
            pmin->per.age=p->per.age;
            strcpy(pmin->per.name,p->per.name);
            strcpy(pmin->per.phone,p->per.phone);
            strcpy(pmin->per.come,p->per.come);
            strcpy(pmin->per.thing,p->per.thing);

            p->per.num=tnum;
            p->per.age=tage;
            strcpy(p->per.name,tname);
            strcpy(p->per.phone,tphone);
            strcpy(p->per.come,tcome);
            strcpy(p->per.thing,tthing);
       
        }
        p=p->next;
    }
    return;
}
void Descending_Sort(TNode* head)
{
    display("　　　　　人员号码降序");
    int tnum;
    int tage;
    char tname[20];
    char tphone[50];
    char tcome[100];
    char tthing[100];
    TNode* p=head;
    TNode* pmax;
    if(p->next==NULL)
    {
        printf("\n无数据，无法排序!\n");
        return;
    }
    while(p)
    {
        pmax=Find_Max_Num(p);
        if(strcmp(pmax->per.name,p->per.name))
        {
            tnum=pmax->per.num;
            tage=pmax->per.age;
            strcpy(tname,pmax->per.name);
            strcpy(tphone,pmax->per.phone);
            strcpy(tcome,pmax->per.come);
            strcpy(tthing,pmax->per.thing);

            pmax->per.num=p->per.num;
            pmax->per.age=p->per.age;
            strcpy(pmax->per.name,p->per.name);
            strcpy(pmax->per.phone,p->per.phone);
            strcpy(pmax->per.come,p->per.come);
            strcpy(pmax->per.thing,p->per.thing);

            p->per.num=tnum;
            p->per.age=tage;
            strcpy(p->per.name,tname);
            strcpy(p->per.phone,tphone);
            strcpy(p->per.come,tcome);
            strcpy(p->per.thing,tthing);
       
        }
        p=p->next;
    }
    return;
    
}
void Read_File(TNode* head)
{
    FILE* fp;
    display("    读取人员信息中");
    fp=fopen("Person","r");
    if(fp==NULL)
    {
        printf("\n文件打开失败!\n");
        Any_Key_Continue();
    }
    Node temp;
    TNode* p=head;
    while(p)
    {
        strcpy(temp.name, p->per.name);
		temp.num=p->per.num;
		temp.age=p->per.age;
		strcpy(temp.come,p->per.come);
		strcpy(temp.thing,p->per.thing);
		if (fread(&temp,sizeof(Node),1,fp) != 1)
		{
			printf("\n读取数据失败!\n");
			sleep(3);
            Any_Key_Continue();
			return;
		}
        p=p->next;
    }
    fclose(fp);
    printf("\n正在读取\n");
    sleep(3);
    display("读取成功!"); 
    Read_File_Show(head);
    Any_Key_Continue();
    return ;
}
void Save_File(TNode* head)
{
    FILE* fp;
    Node temp;
    display("    保存人员信息中");
    fp=fopen("Person","wb+");
    if(fp==NULL)
    {
        printf("\n文件打开失败!\n");
        sleep(3);
        return;
    }
    TNode* p=head;
    while(p)
    {
        strcpy(temp.name, p->per.name);
		temp.num=p->per.num;
		temp.age=p->per.age;
		strcpy(temp.come,p->per.come);
		strcpy(temp.thing,p->per.thing);
		if (fwrite(&temp,sizeof(Node),1,fp) != 1)
		{
			printf("\n写入数据失败!\n");
			sleep(3);
			return;
		}
        p=p->next;
    }
    fclose(fp);
    printf("\n正在保存中!\n");
    sleep(3);
    printf("保存成功!\n");
    Any_Key_Continue();
    return; 
}
void Format()
{
    int i;
    for(i=0;i<50;i++)
        printf("*");

    printf("\n");
}
void Any_Key_Continue()
{
    puts("\n请按任意键继续...");
    getch();
    return;
}
void Report_Printing(TNode* head)
{
    TNode* p=head;
    int cnt=0;
    display("      统计人员信息");
    while(p)
    {
        printf("号码:%d:%s\n",++cnt,p->per.name);
        printf("年龄:%d\n",p->per.age);
        printf("电话号码:%s\n",p->per.phone);
        printf("来自哪里:%s\n",p->per.come);
        printf("备注:%s\n",p->per.thing);
        p=p->next;
        Format();

    }
    printf("本系统一共录入%d人数\n",cnt);
    Format();
    Any_Key_Continue();
    return;
}


void Delete_Person_Menu(TNode*head)
{
    TNode* p=head;
	int i;

    display("     删除人员");
    printf("1.根据人员号码删除\n");
    printf("2.根据人员姓名删除\n");
    printf("0.返回上一步\n");
    Format();
    printf("请输入对应的序号：");
    int pnum;
    i=Get_choice();
    switch (i) 
    {
        case 1:
            printf("请输入要删除的号码:");
            scanf("%d",&pnum);
            p=Delete_Num(p,pnum);
            break;
        //case 2:
          //  Delete_Name();
          //  break;
    }
    //display("      删除成功!");
    sleep(2);
    Any_Key_Continue();
    return;
}
void Find_Person_Menu(TNode* head)
{
    TNode* p=head;
	int i;

    display("        查找人员");
    printf("1.根据人员号码查询\n");
    printf("2.根据人员姓名查询\n");
    printf("3.根据年龄和电话组合查询\n");
    printf("0.返回上一步\n");
    Format();
    printf("请输入对应的数字：");
    while((i=Get_choice())!=0)
    {
        switch (i) 
        {
            case 1:
                Find_Num(p);
                break;
            case 2:
                Find_Name(p);
                break;
            case 3:
                Combined_Query(p);
                break;
        }
        display("        查找人员");
        printf("1.根据人员号码查询\n");
        printf("2.根据人员姓名查询\n");
        printf("3.根据年龄和电话组合查询\n");
        printf("0.返回上一步\n");
        Format();
    }
    Any_Key_Continue();
    return;
}
void Sort_Person_Menu(TNode* head)
{
    int choice;
    TNode* p=head;
    display("       排序人员信息");
    printf("1.按人员号码升序排序\n");
    printf("2.按人员号码降序排序\n");
    printf("0.返回上一步\n");
    Format();
    printf("请输入对应的数字：");
    choice=Get_choice();
    int flag=0;
    switch(choice) 
    {
        case 1:
            Ascending_Sort(p);
            flag=1;
            break;
        case 2:
            Descending_Sort(p);
            flag=1;
            break;
    }
    if(flag)
    {
        display("       排序成功!");
        sleep(2);
    }
    Menu();
    sleep(2);
    return;
}
void Login_Menu()
{
  
    display("   人员流动管理系统");

    printf("1.登录系统\n");
    printf("2.新用户注册\n");
    printf("3.找回密码\n");
    printf("4.开发者说明\n");
    printf("0.退出系统\n");
    Format();
    Create_User_File();
    printf("请输入对应的数字:");
    int choice;
    while(choice=Get_choice())
    {
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
                break;
            case 0:
                display("      退出成功!");
                sleep(3);
                return;
        }

        display("   人员流动管理系统");
        printf("1.登录系统\n");
        printf("2.新用户注册\n");
        printf("3.找回密码\n");
        printf("4.开发者说明\n");
        printf("0.退出系统\n");
        Format();
    }
    return;
}
void Menu()
{
    TNode* head;

    Create_Person_File();
    head=Create();

    display("    人员流动管理系统");
    printf("1.添加人员信息\n");
    printf("2.删除人员信息\n");
    printf("3.修改人员信息\n");
    printf("4.查找人员信息\n");
    printf("5.人员排序\n");
    printf("6.打印所有人员信息\n");
    printf("7.读取人员信息\n");
    printf("8.保存人员信息\n");
    printf("9.统计人员信息\n");
    printf("0.退出登录\n");
    Format();
    printf("请输入对应的数字:\n");
    int choice;
    while((choice=Get_choice())!=0)
    {
        switch (choice)
        {
            case 1:
                Add_Tail(&head);
                break;
            case 2:
                Delete_Person_Menu(head);
                break;
            case 3:
                Change_Num(head);
                break;
            case 4:
                Find_Person_Menu(head);
                break;
            case 5:
                Sort_Person_Menu(head);
                break;
            case 6:
                Show(head);
                break;
            case 7:
                Read_File(head);
                break;
            case 8:
                Save_File(head);
                break;
            case 9:
                Report_Printing(head);
                break;
        }
         display("    人员流动管理系统");
            printf("1.添加人员信息\n");
            printf("2.删除人员信息\n");
            printf("3.修改人员信息\n");
            printf("4.查找人员信息\n");
            printf("5.人员排序\n");
            printf("6.打印所有人员信息\n");
            printf("7.读取人员信息\n");
            printf("8.保存人员信息\n");
            printf("9.统计人员信息\n");
            //printf("4.查找人员信息\n");
            printf("0.退出登录\n");
            Format();
    }
    Any_Key_Continue();
    Free_Node(&head);
    return;
}
void Developor()
{
    display("       作者简介");
    //system("sleep 1");
    printf("        >作者:bokette\n");
    printf("-------------------------------------\n");
    printf("        >邮箱:bokket@XiyouLinuxGroup\n");
    printf("        >学校:XUPT\n");
    printf("        >班级:DSBD-1902\n");
    printf("------------------------------------\n");
    Any_Key_Continue();
    return;
}
int Get_int()
{
    int n;
    char ch;
    while(scanf("%d",&n)!=1)
	{
		while((ch=getchar())!='\n')
			putchar(ch);
		printf("不是一个整数!\n请重新输入:\n");
	}
    clear_buffer();
	return n;
}
char* Get_string(char* str,int n)
{
    char* s;
    int i=0;
    s=fgets(str,n,stdin);
	if(s!=NULL)
	{
		while(s[i]!='\0' && s[i]!='\n')
			i++;
		if(s[i]=='\n')
			s[i]='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return s;
}
int Get_choice()
{
    int choice;
    choice=Get_int();
    while(!(choice>=1 && choice<=9 || choice==0))
    {
        puts("请重新输入");
        choice=Get_int();
    }
    return choice;
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
        if(ch=='\x7F')//当密码输入为空格键并且输入字符数大于１时
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
void Enter()
{
    user old,new;
    FILE* fp;
    char temp[MAX];
    display("请登入\n");

    if((fp=fopen("user","r"))==NULL)
    {
        sys_err("fopen error!\n");
        printf("打开文件失败！\n");
        return;
    }
    puts("请输入账号:");
    while(scanf("%s",temp)!=1)
    {
        printf("账号错误!\n");
        clear_buffer();
    }
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
                sleep(3);
                Any_Key_Continue();
                Menu();
                return;
            }
            else
            {
                puts("密码错误!\n");
                sleep(3);
                Any_Key_Continue();
                return;
            }
        }
    }
       
    printf("账号%s不存在!\n",temp);
    fclose(fp);
    sleep(3);
    Any_Key_Continue();
    return;
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
        printf("输入错误!,请重新输入！\n");
        clear_buffer();
    }
    getchar();

    while(fread(&old,sizeof(struct user),1,fp))
    {
        if(strcmp(new.id,old.id)==0)
        {
            printf("\n账号重复!\n");
            fclose(fp);
            sleep(2);
            Any_Key_Continue();
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
            sleep(3);
            fclose(fp);
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
        printf("打开文件失败！\n");
        return;
    }
    puts("请输入账号:");
    while(scanf("%s",temp)!=1)
    {
        printf("输入错误!\n");
        clear_buffer();
    }
    getchar();


    while(!feof(fp))
    {
        fread(&old,sizeof(user),1,fp);
        if(strcmp(temp,old.id)==0)
        {
            puts("请输入电话号码:");
            if((num=Get_Num())==old.telephonenum)
            {
                printf("找回的密码是:%s\n",old.password);
                printf("找回成功!正在返回登录界面..\n");
            }
            else
            {
                printf("电话号码错误\n");
                printf("正在返回登录界面....\n");
            }
            sleep(3);
            fclose(fp);
            return;
        }
    }
       
    printf("账号%s不存在\n",temp);
    printf("正在返回登录界面....\n");
    sleep(2);
    Any_Key_Continue();
    Login_Menu();
    fclose(fp);
    return ;
}
void Create_Person_File()
{
	FILE * fp;
	if ((fp=fopen("Person","r"))==NULL)
	{
		if((fp=fopen("Person","w+"))==NULL)
		{
			sys_err("fopen error!");
            sleep(3);
			return;
		}
	}
	fclose(fp);
	return;
}
void Create_User_File()
{
	FILE * fp;

	if((fp=fopen("user","r"))==NULL)	
	{
		if((fp=fopen("user","w+"))==NULL)
		{
			sys_err("fopen error!");
            sleep(3);
			return;
		}
	}
	fclose(fp);
	return ;
}