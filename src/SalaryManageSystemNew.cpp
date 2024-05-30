/*
 * SalaryManageSystemNew.cpp
 * Created by 沙杰杰 on 2024/5/20.
 * 控制台主函数
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "file_action.h"
#include "data_define.h"
#include "balance_calculate.h"
#include <vector>


using namespace OpenXLSX;
using namespace std;


/*******************************************************
功能: 显示菜单
*******************************************************/
void displayMenu() {
    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+               个人收支管理系统MAX                     +\n");
    printf("+                                                       +\n");
    printf("+                 1. 输入个人信息(第一次进入请选择)     +\n");
    printf("+                 2. 本次总收入和总支出统计                      +\n");
    printf("+                 3. 全部总收入和总支出统计                      +\n");
    printf("+                 4. 收支记录管理                       +\n");
    printf("+                 5. 本次收支清单打印                       +\n");
    printf("+                 6. 全部收支清单打印                 +\n");
    printf("+                 7. 查询当前个人信息及余额             +\n");
    printf("+                 8. 保存到文件                         +\n");
    printf("+                 9. 程序结束                           +\n");
    printf("+                                                       +\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

/*******************************************************
功能: 登陆函数，验证口令
*******************************************************/
int login(char password[]) {
    static char key[30] = "123";
    if (strcmp(password, key) == 0)
        return 1;
    else
        return 0;
}

/*******************************************************
功能: 个人信息进行添加
*******************************************************/
void add_personal(personal &pe) {
    printf("\n请输入您的姓名(只限英文名)\n");
    scanf("%s", pe.name);
    printf("请输入您的性别(m为男性,w为女性)\n");
    scanf(" %c", &pe.sex);  // 注意这里的空格，防止读取空字符
    printf("请输入您的年龄\n");
    scanf("%d", &pe.age);
    printf("请输入您的地址(限用拼音或英文,中间加空格)\n");
    scanf("%s", pe.add);
    printf("请输入您的电话(只需要一个)\n");
    scanf("%s", pe.tel);
    printf("请输入您的余额\n");
    scanf("%lf", &pe.yue);
    printf("您的个人信息已经输入完毕,下面请输入您的收支记录\n");

}

/*******************************************************
功能: 个人信息进行添加
*******************************************************/
void add_record(vector<record> &re){
    int i = 0;
    char p = 'y';  // 初始化为 'y'，以便进入循环
    while (p != 'n' && i < N) {  // 使用 while 循环更清晰
        record rec;
        printf("年\n");
        scanf("%d", &rec.year);
        printf("月\n");
        scanf("%d", &rec.month);
        printf("日\n");
        scanf("%d", &rec.day);
        printf("收入或者支出(收入为+,支出为-)\n");
        scanf(" %c", &rec.shouzhi);  // 直接使用空格处理前一个输入的换行符
        printf("收入或者支出的数额\n");
        scanf("%lf", &rec.money);
        printf("请输入原因(只限拼音或者英文)\n");
        scanf("%s", rec.reason);

        re.push_back(rec);

        printf("是否还要继续输入y/n\n");
        scanf(" %c", &p);  // 读取用户是否继续的决定

        i++;  // 递增循环计数器
    }
}

/***************************************************
收支记录管理
****************************************************/
void guanli(vector<record> &re) {
    int i, xuanze2, xuanze3;
    char p;
    int xuanze = 0;
    printf("请选择您想进行的操作\n");
    printf("1.添加新的收支信息\n");
    printf("2.删除已有信息\n");
    printf("3.修改已有信息\n");
    scanf("%d", &xuanze);
    switch (xuanze) {
        case 1:
            for (i = re.size(); p != 'n' && i < N; i++) {
                record rec;
                printf("年\n");
                scanf("%d", &rec.year);
                printf("月\n");
                scanf("%d", &rec.month);
                printf("日\n");
                scanf("%d", &rec.day);
                printf("收入或者支出(收入为+,支出为-)\n");
                getchar();
                scanf("%c", &rec.shouzhi);
                printf("收入或者支出的数额\n");
                scanf("%lf", &rec.money);
                printf("请输入原因(只限拼音或者英文)\n");
                scanf("%s", rec.reason);

                re.push_back(rec);

                if (i < N) {
                    printf("是否还要继续输入y/n\n");
                    scanf(" %c", &p);  // 注意这里的空格，防止读取空字符
                }
            }
            break;
        case 2:
            printf("您想删除第几条记录?\n");
            scanf("%d", &xuanze2);
            if (xuanze2 >= 0 && xuanze2 < re.size()) {
                re.erase(re.begin() + xuanze2);
            } else {
                printf("无效的记录编号\n");
            }
            break;
        case 3:
            printf("您想修改哪一条记录?\n");
            scanf("%d", &xuanze3);
            if (xuanze3 >= 0 && xuanze3 < re.size()) {
                printf("请您重新输入这一条记录\n");
                record rec;
                printf("年\n");
                scanf("%d", &rec.year);
                printf("月\n");
                scanf("%d", &rec.month);
                printf("日\n");
                scanf("%d", &rec.day);
                printf("收入或者支出(收入为+,支出为-)\n");
                getchar();
                scanf("%c", &rec.shouzhi);
                printf("收入或者支出的数额\n");
                scanf("%lf", &rec.money);
                printf("请输入原因(只限拼音或者英文)\n");
                scanf("%s", rec.reason);

                re[xuanze3] = rec;
            } else {
                printf("无效的记录编号\n");
            }
            break;
    }
}


/*******************************************************
功能: 主函数
参数：无
返回值：int类型
*******************************************************/
int main() {

    int row = 2;
    int count = 0;
    int choice = 0; /* select and store menu item */
    int s = 0, arrayLength = 0;
    char password[10];

    /* 初始化每次输入存储在结构体中的数据 */
    personal pe;
    vector<record> re;

    /* 初始化读取文件的结构体*/
    readpersonal pe_read;
    readrecord re_read;
    readFromFile1(pe_read);
    readFromFile2(row,re_read);

    float disbursetotal = disburseCalculate(row, 0);
    float incometotal = incomeCalculate(row, 0);


    /*====验证用户的口令，直到正确为止====*/
    do {
        printf("请输入包装盒上的密钥：\n");
        scanf("%s", password);

        s = login(password);
    } while (s == 0);


    /*====根据用户的选择，执行相应的操作.====*/
    while (1) {
        displayMenu();
        printf("\n 请选择您的操作(1,2,3,4,5,6,7,8)：\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_personal(pe);
                printf("\n个人信息输入成功\n");
                writeToFile1(pe);
                add_record(re);
                printf("\n收支信息输入成功\n");
                break;
            case 2:
//                tongji(re);
                break;
            case 3:
                cout << "Total income: " << disbursetotal << endl; // 输出总支出
                cout << "Total income: " << incometotal << endl; // 输出总收入
                break;
            case 4:
                guanli(re);
                break;
            case 5:

                break;
            case 6:
                printPersonal();
                printRecord(row,count);
                break;
            case 7:
                balance_change(row);
                printPersonal();
                break;
            case 8:
                writeToFile2(re);
                break;
            case 9:
                exit(0);
                break;
        }
    }
    return 0;
}
