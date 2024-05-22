 #include "stdio.h"
#include "stdlib.h"
#include "string.h"
 
 
#define N 30
#define FILENAME1 "/Users/shajiejie/Desktop/personal.txt"
#define FILENAME2 "/Users/shajiejie/Desktop/money.txt"
 struct personal
{
    char name[10];         /*姓名*/
    char sex;              /*性别*/
    float age;             /*年龄*/
	char add[40];          /*地址*/
	char tel[20];          /*电话*/
	float yue;             /*余额*/
	
};
 struct record
 {
	 int year;
	 int month;
	 int day;
	 char shouzhi;
	 float money;
	 char reason[50];
};
 
 
/*******************************************************       
功能:显示菜单
 *******************************************************/
 void displayMenu()
 {
 
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               个人收支管理系统MAX                     +\n");
		printf("+                                                       +\n");
        printf("+                 1. 输入个人信息(第一次进入请选择)     +\n");
        printf("+                 2. 收支记录管理                       +\n");
        printf("+                 3. 收支清单打印                       +\n");
        printf("+                 4. 总收入和总支出统计                 +\n");
        printf("+                 5. 查询当前个人信息及余额             +\n");
        printf("+                 6. 保存到文件                         +\n");
        printf("+                 7. 程序结束                           +\n");
        printf("+                                                       +\n");
		printf("+                                                       +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
 
 }
 
/*******************************************************       
功能:登陆函数，验证口令
 *******************************************************/
 int login(char password[])
 {
     static char key[30]="123";
     if(strcmp(password,key)==0)
       return 1;
     else
       return 0;
  }
  /*******************************************************       
功能:从文件读信息到结构体数组中
 *******************************************************/
 
void readFromFile1(struct personal *pe) {
    FILE *fp = fopen(FILENAME1, "rb");

    if (fp != NULL) {
        fread(pe, sizeof(struct personal), 1, fp);
        fclose(fp);
    } else {
        printf("无法打开文件 %s\n", FILENAME1);
    }
}

void readFromFile2(struct record re[], int length) {
    FILE *fp = fopen(FILENAME2, "rb");
    int i = 0;

    if (fp != NULL) {
        while (i < length && fread(&re[i], sizeof(struct record), 1, fp) == 1) {
            i++;
        }
        fclose(fp);
    } else {
        printf("无法打开文件 %s\n", FILENAME2);
    }
}

 
 /*******************************************************       
功能:输入信息到结构体数组中
 
 *******************************************************/
int inputInfo(struct personal &pe,struct record re[])
{
    int i;
	char p;
	printf("\n请输入您的姓名(只限英文名)\n");
	scanf("%s",pe.name);
	printf("请输入您的性别(m为男性,w为女性)\n");
	scanf("%s",&pe.sex);
	printf("请输入您的年龄\n");
	scanf("%f",&pe.age);
	printf("请输入您的地址(限用拼音或英文,中间加空格)\n");
	scanf("%s",pe.add);
	printf("请输入您的电话(只需要一个)\n");
	scanf("%s",pe.tel);
    printf("请输入您的余额");
	scanf("%f",&pe.yue);
	printf("您的个人信息已经输入完毕,下面请输入您的收支记录\n");
	for(i=0;p!='n'&&i<N;i++)
	{
		printf("年");
		scanf("%d",&re[i].year);
		printf("月");
		scanf("%d",&re[i].month);
		printf("日");
		scanf("%d",&re[i].day);
		printf("收入或者支出(收入为+,支出为-)\n");
		getchar();
		scanf("%c",&re[i].shouzhi);
		printf("收入或者支出的数额\n");
		scanf("%f",&re[i].money);
		printf("请输入原因(只限拼音或者英文)\n");
		scanf("%s",re[i].reason);
		
		if(i<N)
		{
			printf("是否还要继续输入y/n");
			scanf("%s",&p);
		}	
	}
    return i;
}
/***************************************************
收支记录管理
****************************************************/
void guanli(struct record re[],int length)
{
	int i,xuanze2,xuanze3;
	char p;
	int xuanze=0;
	printf("请选择您想进行的操作");
	printf("1.添加新的收支信息");
	printf("2.删除已有信息");
	printf("3.修改已有信息");
	scanf("%d",&xuanze);
    switch(xuanze)
	{
	case 1:
		for(i=length;p!='n'&&i<N;i++)
	{
		printf("年");
		scanf("%d",&re[i].year);
		printf("月");
		scanf("%d",&re[i].month);
		printf("日");
		scanf("%d",&re[i].day);
		printf("收入或者支出(收入为+,支出为-)\n");
		getchar();
		scanf("%c",&re[i].shouzhi);
		printf("收入或者支出的数额\n");
		scanf("%f",&re[i].money);
		printf("请输入原因(只限拼音或者英文)\n");
		scanf("%s",re[i].reason);	
		if(i<N)
		{
			printf("是否还要继续输入y/n");
			scanf("%s",&p);
		}	
	}
		break;
	case 2:
		printf("您想删除第几条记录?");
        scanf("%d",&xuanze2);
		for(i=xuanze2;i<=length;i++)
            re[i]=re[i+1];
        break;
	case 3:
		printf("您想修改哪一条记录");
        scanf("%d",&xuanze3);
		i=xuanze3; 
		printf("请您重新输入这一条记录");
		printf("年");
		scanf("%d",&re[i].year);
		printf("月");
		scanf("%d",&re[i].month);
		printf("日");
		scanf("%d",&re[i].day);
		printf("收入或者支出(收入为+,支出为-)\n");
		getchar();
		scanf("%c",&re[i].shouzhi);
		printf("收入或者支出的数额\n");
		scanf("%f",&re[i].money);
		printf("请输入原因(只限拼音或者英文)\n");
		scanf("%s",re[i].reason);	
		break;
	}
	
 
}
 
 /*******************************************************       
功能:打印收支清单
 *******************************************************/
void outputInfo(struct record re[],int length)
{
	int i;
	printf("************************收支清单****************************\n");
	printf("日期                                                    收支\n");
	for(i=0;i<length;i++)
		printf("%d.%d.%d                                              %c%f\n",re[i].year,re[i].month,re[i].day,re[i].shouzhi,re[i].money);
 
	
}
/************************************
总收入和支出统计
************************************/
void tongji(struct record re[],int length)
{
	float s,z;
	int i;
	s=0,z=0;
	for(i=0;i<length;i++) 
	{  
		if(re[i].shouzhi=='+')
	         s=s+re[i].money;
		else
			 z=z+re[i].money;
	}
	printf("总收入=%f\n",s);
	printf("总支出=%f\n",z);
	
}
/****************************************************
查询个人信息以及余额
****************************************************/
void chaxun(struct personal pe,struct record re[],int length)
{
	float total=0,ye;
	int i;
	for(i=0;i<length;i++) 
	{
		if(re[i].shouzhi=='+')
	         total=total+re[i].money;
		else
	         total=total-re[i].money;
	}
	ye=pe.yue+total;
	printf("\n姓名)\n");
	printf("%s\n",pe.name);
	printf("性别\n");
	printf("%c\n",pe.sex);
	printf("年龄\n");
	printf("%f\n",pe.age);
	printf("地址)\n");
	printf("%s\n",pe.add);
	printf("电话\n");
	printf("%s\n",pe.tel);
	printf("余额\n");
    printf("%f\n",ye);
}	
 
 

/*******************************************************       
功能:结构体数组中的学生信息输出到文件
 *******************************************************/
void writeToFile1(struct personal pe) {
    FILE *fp = fopen(FILENAME1, "wb");
    if (fp == NULL) {
        printf("打开文件出错！\n");
        exit(0);
    }
    fwrite(&pe, sizeof(struct personal), 1, fp);
    fclose(fp);
}

int writeToFile2(struct record re[], int length) {
    FILE *fp = fopen(FILENAME2, "wb");
    if (fp == NULL) {
        printf("打开文件出错！\n");
        exit(0);
    }
    for (int i = 0; i < length; i++)
        fwrite(&re[i], sizeof(struct record), 1, fp);
    fclose(fp);
    return length;
}

 
 /*******************************************************       
  功能:主函数
  参数：无   
  返回值：int类型
 *******************************************************/
int main()
{
	struct personal pe;
	struct record re[N];
    int length=0;
    int choice = 0; /*select and store menu item  */
    int s=0,arrayLength=0;
    char password[10];
 
    /*====验证用户的口令，直到正确为止====*/
	do{
		printf("请输入包装盒上的密钥：");
		scanf("%s",password);
 
		s=login(password);
     }while(s==0);
	length=writeToFile2(re,length);
 
 
    /*====根据用户的选择，执行相应的操作.====*/
    while(1)
    {
 
		displayMenu();
 
		printf("\n 请选择您的操作(1,2,3,4,5,6,7,8)：\n");
        scanf("%d",&choice);
 
		switch(choice)
        {
 
			case 1:
				length=inputInfo(pe,re);
				printf("\n个人信息输入成功\n");
				break;
 
			case 2:
			    guanli(re,length);
				break;
  
			case 3:
				outputInfo(re,length);
				break;
 
			case 4:
				tongji(re,length);
				break;
            case 5:
				chaxun(pe,re,length);
				break;
            case 6:
				writeToFile1(pe);
				writeToFile2(re,length);
 
				break;
            case 7:
				exit(0);
				break;
        }
    }
  return 0;
}
