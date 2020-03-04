#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct shandong//结构体 
{
	char shiname[20];
	char shizhangname[20];
	char phone[13];
	char postcode[10];
	int  people;
	int area;
	struct shandong *next;
	
 }shan;
 shan * head;
 //菜单函数 
 print()
 {
 	printf("******************************************************************************************************\n");
 	printf("######################################################################################################\n");
 	printf("                                   山东区市管理系统\n\n");
 	printf("                           1.信息录入                           2.信息报表\n");
 	printf("                           3.信息插入                           4.信息删除\n");
 	printf("                           5.信息查询                           6.信息修改\n");
 	printf("                           7.信息保存                           8.信息读取\n");
 	printf("                           9.信息统计                           10.数据排序\n");
 	printf("                                               11.返回菜单\n")
 	printf("_______________________________________________________________________________________________________\n");
 	printf("^^^^^^^^^^^^^^^^^^^^^^^^退^^^^^^^^^^^出^^^^^^^^^^请^^^^^^^^^^^^按^^^^^^^^^^0^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
 	printf("————————————————————————————————----------------------------------——-\n");
}
//数据输入 
void inputdate(shan * p1)
{
	shan *p2;
	if(p1!=NULL)
	{
		printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("                                  输入数据                                               \n");
		printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\n\n");
		printf("                      请输入信息，市名处输入ok结束\n");
		while(1)
		{
			printf("市名:");
		    scanf("%s",&p1->shiname);
		  if(strcmp(p1->shiname,"ok")==0)
		    {
			    
			    printf("输入结束\n");
		     	p2->next=NULL;
		    	free(p1);
		    	p1=p2;
		    	break;
	     	}
	     	
	     	else
	     	{ 
	     		printf("\n市长名字:");
	     		scanf("%s",&p1->shizhangname);
	     		printf("\n市长电话:");
	     		scanf("%s",&p1->phone);
	     		printf("\n本市邮编:");
				scanf("%s",&p1->postcode);
				printf("\n人口数量:");
				scanf("%d",&p1->people);
				printf("\n地域面积:");
				scanf("%d",&p1->area);
				printf("______________________________________________________________\n");
				p2=p1;
				
				p1=(shan *)malloc(sizeof(shan));	
				p2->next=p1; 		
			
			    
			 }
        
    	}
	}
	
}
//信息显示 
void lookdate(shan * p1)
{
	
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\n\n");
	printf("                         信息报表                          \n");
	printf("___________________________________________________________\n");
	printf("\n\n\n");
	if(p1==NULL)
    {
 	printf("什么也没有\n\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	return;
    }
	while (p1!=NULL)
	{
		printf("市名:%s  ",p1->shiname);
		printf("市长名:%s  ",p1->shizhangname);
		printf("市长电话:%s  ",p1->phone);
		printf("本市邮编:%s  ",p1->postcode);
		printf("本市人口:%d  ",p1->people);
		printf("本市地域面积:%d\n",p1->area);
		printf("\n\n");
		printf("________________________________________________________\n\n");
		p1=p1->next;
	}

	
} 
//信息插入
void insert ()
{	int i=0;
    char name [20];
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\n\n");
    printf("                      信息插入                                         \n");
    printf("\n\n\n");
    shan *p2,*p1,*p3;
    p1=head;//p1=head;
	p3=(shan *)malloc(sizeof(shan));
	p3->next=NULL;
	printf("请输入插入的信息\n");
	            printf("市名字:");
            	scanf("%s",&p3->shiname);
		        printf("\n市长名字:");
	     		scanf("%s",&p3->shizhangname);
	     		printf("\n市长电话:");
	     		scanf("%s",&p3->phone);
	     		printf("\n本市邮编:");
				scanf("%s",&p3->postcode);
				printf("\n人口数量:");
				scanf("%s",&p3->people);
				printf("\n地域面积:");
				scanf("%s",&p3->area);
	printf("请输入要插入哪个市的前面:");
	scanf("%s",name);
	while(strcmp(p1->shiname,name)!=0)
	{
		p2=p1;
		p1=p1->next;
		i=1;
				
	}
	if(i==0)//插在第一个 
	{
		p3->next=p1;
	    head=p3;
	    printf("插入成功\n");
	    printf("\n\n\n");
	    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	

	if(i==1)//插在中间 
	{
	p2->next=p3;
	p3->next=p1; 
	printf("插入成功\n");
	printf("\n\n\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}

	
	
	
}

//信息删除
void deleated ()
{
	char name[20];
	shan *p1,*p2;
	p1=head;p2=head;
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n");
	printf("                              信息删除\n");
	printf("\n"); 
	printf("请输入要删除的市名:");
	scanf("%s",name);
	if(head==NULL)
	{
		printf("什么也没有\n");
		printf("\n\n\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		
		return; 
	}
	if(strcmp(p1->shiname,name)==0)
	{
		head=p1->next;
		printf("\n\n\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		return;
	}
	while(p1!=NULL)
	{
	if(strcmp(p1->shiname,name)==0)
	{
	    	if(p1->next=NULL)
	    	{
	    		p2->next=NULL;
	    		printf("删除成功\n");
	    		printf("\n\n\n");
	    		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	    		return;
			}
			else
			{
				p2->next=p1->next;
				printf("删除成功\n");
	    		printf("\n\n\n");
	    		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				return;
			}
			
			
	}
		p2=p1;
		p1=p1->next;
	}
}

//信息查询
void finddate(shan *p1) 
{
	int i=0;
	char name[20];
     printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
	 printf("                           信息查询\n"); 
	if(p1->next==NULL)
	{
		printf("什么也没有");
		printf("\n\n\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	
	printf("请输入要查询的市名:");
	scanf("%s",name);
	while(p1!=NULL)
	{
		if(strcmp(p1->shiname,name)==0)
		{
		printf("市名:%s  ",p1->shiname);
		printf("市长名:%s  ",p1->shizhangname);
		printf("市长电话:%s  ",p1->phone);
		printf("本市邮编:%s  ",p1->postcode);
		printf("本市人口:%d  ",p1->people);
		printf("本市地域面积:%d\n",p1->area);
		printf("\n\n\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("\n\n\n");
		i=1;
		break;
		}		
		p1=p1->next;
        
	}
	if(i==0)
	printf("没有该市\n");
	printf("\n\n\n\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
}
//信息修改
void update(shan *p1)
{
	int i=0;
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
	printf("                             信息修改\n");
	printf("请输入要修改的市名:\n");
	char name[20];
	scanf("%s",name);
	while(p1!=NULL)
	{
		if(strcmp(p1->shiname,name)==0)
		{
		printf("该市信息\n");
		printf("1.市名:%s  ",p1->shiname);
		printf("2.市长名:%s  ",p1->shizhangname);
		printf("3.市长电话:%s\n  ",p1->phone);
		printf("4.本市邮编:%s  ",p1->postcode);
		printf("5.本市人口:%d  ",p1->people);
		printf("6.本市地域面积:%d\n",p1->area);
		printf("___________________________________________________________________________\n");
		printf("请输入要修改的编号:");
		scanf("%d",&i);
		printf("请输入新信息:");
		switch(i)
		{
			case 1 : scanf("%s",&p1->shiname);break;
			case 2 : scanf("%s",&p1->shizhangname);break;
			case 3 : scanf("%s",&p1->phone);break;
			case 4 : scanf("%s",&p1->postcode);break;
			case 5 : scanf("%d",&p1->people);break;
			case 6 : scanf("%d",&p1->area);break;
		}
		i=1;
		printf("                 修改数据完成\n");
		printf("\n\n\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		break;
		}
		p1=p1->next;
	}
	if(i==0)
	{
		printf("               没有该市\n\n\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
 } 
/*//信息保存
void save ()
{
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
	printf("                            信息保存\n\n");
	shan * p1;
	p1=head;
	FILE *fp;
	
	if((fp=fopen("d:\\课设.txt","w"))==NULL)
	{
		printf("打开文件失败");
		getch();
		return;
	}
	fprintf(fp,"市名\t市长名\t市长电话\t本市邮编\t本市人口\t本市地域面积\n");
	while(p1!=NULL)
	{
		fprintf(fp,"%s\t",p1->shiname);
		fprintf(fp,"%s\t",p1->shizhangname);
		fprintf(fp,"%s\t",p1->phone);
		fprintf(fp,"%s\t",p1->postcode);
		fprintf(fp,"%d\t",p1->people);
		fprintf(fp,"%d\t",p1->area);
		p1=p1->next;
	}
	printf("                             储存完成\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	
 } */
void save()
{
    FILE *fp;  
    shan *p;  
    if((fp=fopen("课设.txt","at"))==NULL)
		printf("Can not open the file!");  
    p=head;  
    while(p!=NULL)
	{  
		if(fwrite(p,sizeof(shan),1,fp)!=1)
		{
			printf("写入数据出错\n");  
			fclose(fp);
			break;
        }  
        p=p->next;  
    }  
    fclose(fp);  
	printf("存储完成\n");
	system("pause");
	system("cls");
}
void read()
{
	FILE *fp;
	shan *p1,*p2;
	if((fp=fopen("课设.txt","rb+"))==NULL)
	{printf("Can not open file!");exit(0);}
	p2=head;
    do
	{ 
		p1=(shan *)malloc(sizeof(shan));                              
		p2->next=p1;
		fread(p1,sizeof(shan),1,fp);
		p2=p1;
	
    }while(p2->next!=NULL);
    fclose(fp);
	printf("读取完成!\n\n");
	system("pause");
	system("cls");
}
void area()
{
	shan * p1;
	p1=head;
	printf("请输入要统计多少面积及以上的城市:");
	int k;
	int sum=0;
	scanf("%d",&k);
	while(p1!=NULL)
	{
		if(p1->area>=k)
		sum++;
		p1=p1->next;
	}
	printf("符合条件的一共有%d个\n",sum);
	free(p1);
}
void people()
{
	shan * p1;
	p1=head;
	printf("请输入要统计多少人口及以上的城市:");
	int k;
	int sum=0;
	scanf ("%d",&k);
	while(p1!=NULL)
	{
		if(p1->people>=k)
		sum++;
		p1=p1->next;
	}
	printf("符合条件的一共有%d个\n",sum);
	free(p1);
}
void  statistic()//数据统计 
{
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("                               数据统计\n");
	printf("\n\n");
	printf("1.人口数量           2.占地面积"); 
	printf("请输入要统计什么:");
	int i;
	scanf("%d",&i);
	switch(i)
	{
		case 1 : people();break;
		case 2 : area();break;
	}
	printf("统计完成\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}
/*void pai()
{
	shan * p1,*p2;
	p1=head;
	int k;
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("                                   数据排序\n");
	printf("\n\n\n");
	int n=0;
	while(p1->next!=NULL)
	{
		n++;
		p1=p1-next;
	}
	
	
}*/

//主函数 
 int main()
 {
 	 
	head=(shan *)malloc(sizeof(shan));
 	int i;
 	system("color 4e");
 	print();
    while(1)
{
 		
	 
    printf("请输入您需要的操作的编号：\n");//选择执行的操作 
    scanf("%d",&i);
    while(i<0||i>12)
	{
	     printf("请正确输入您需要操作的编号\n"); 
		 scanf("%d",&i);
	
	}
	if(i==0)
	{
		printf("欢迎下次使用");
		break;
	}
	switch(i)
	{
		
		case 1 : inputdate(head);
		         break;
		case 2 : lookdate(head);
		         break;
		case 3 : insert(head);
		         break;
		case 4 : deleated(head);
		         break;
		case 5 : finddate(head);
		         break;
		case 6 : update(head);
		         break;
		case 7 : save();
		         break;
		case 8 : read();
		         break;
		case 9 : statistic();
		         break;
		/*case 10 :paixu();
		         break;*/
		case 11: print();
		         break;
		         
	}
}

 }
	

