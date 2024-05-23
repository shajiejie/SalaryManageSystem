#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <OpenXLSX.hpp>
#include <vector>
#include <string>

#define N 30
#define FILENAME1 "/Users/shajiejie/Desktop/persenal.xlsx"
#define FILENAME2 "/Users/shajiejie/Desktop/money.xlsx"

using namespace OpenXLSX;
using namespace std;

struct personal {
    char name[10];         /* 姓名 */
    char sex;              /* 性别 */
    float age;             /* 年龄 */
    char add[40];          /* 地址 */
    char tel[20];          /* 电话 */
    float yue;             /* 余额 */
};

struct record {
    int year;
    int month;
    int day;
    char shouzhi;
    float money;
    char reason[50];
};

/*******************************************************
功能: 显示菜单
*******************************************************/
void displayMenu() {
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
功能: 从文件读信息到结构体数组中
*******************************************************/
void readFromFile1(personal &pe) {
    XLDocument doc;
    doc.open(FILENAME1);

    auto wks = doc.workbook().worksheet("Personal");

    strcpy(pe.name, wks.cell("A2").value().get<std::string>().c_str());
    pe.sex = wks.cell("B2").value().get<std::string>()[0];
    pe.age = wks.cell("C2").value().get<double>();
    strcpy(pe.add, wks.cell("D2").value().get<std::string>().c_str());
    strcpy(pe.tel, wks.cell("E2").value().get<std::string>().c_str());
    pe.yue = wks.cell("F2").value().get<double>();

    doc.close();
}

void readFromFile2(vector<record> &re) {
    XLDocument doc;
    doc.open(FILENAME2);

    auto wks = doc.workbook().worksheet("Records");

    int row = 2;
    while (!wks.cell(row, 1).value().get<std::string>().empty()) {
        record rec;
        rec.year = wks.cell(row, 1).value().get<int>();
        rec.month = wks.cell(row, 2).value().get<int>();
        rec.day = wks.cell(row, 3).value().get<int>();
        rec.shouzhi = wks.cell(row, 4).value().get<std::string>()[0];
        rec.money = wks.cell(row, 5).value().get<double>();
        strcpy(rec.reason, wks.cell(row, 6).value().get<std::string>().c_str());
        re.push_back(rec);
        row++;
    }

    doc.close();
}

/*******************************************************
功能: 结构体数组中的学生信息输出到文件
*******************************************************/
void writeToFile1(const personal &pe) {
    XLDocument doc;
    doc.create(FILENAME1);
    auto wks = doc.workbook().worksheet("Personal");

    wks.cell("A1").value() = "姓名";
    wks.cell("B1").value() = "性别";
    wks.cell("C1").value() = "年龄";
    wks.cell("D1").value() = "地址";
    wks.cell("E1").value() = "电话";
    wks.cell("F1").value() = "余额";

    wks.cell("A2").value() = pe.name;
    wks.cell("B2").value() = string(1, pe.sex);
    wks.cell("C2").value() = pe.age;
    wks.cell("D2").value() = pe.add;
    wks.cell("E2").value() = pe.tel;
    wks.cell("F2").value() = pe.yue;

    doc.save();
    doc.close();
}

void writeToFile2(const vector<record> &re) {
    XLDocument doc;
    doc.create(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");

    wks.cell("A1").value() = "年";
    wks.cell("B1").value() = "月";
    wks.cell("C1").value() = "日";
    wks.cell("D1").value() = "收支";
    wks.cell("E1").value() = "数额";
    wks.cell("F1").value() = "原因";

    for (size_t i = 0; i < re.size(); ++i) {
        wks.cell(i + 2, 1).value() = re[i].year;
        wks.cell(i + 2, 2).value() = re[i].month;
        wks.cell(i + 2, 3).value() = re[i].day;
        wks.cell(i + 2, 4).value() = string(1, re[i].shouzhi);
        wks.cell(i + 2, 5).value() = re[i].money;
        wks.cell(i + 2, 6).value() = re[i].reason;
    }

    doc.save();
    doc.close();
}

/*******************************************************
功能: 输入信息到结构体数组中
*******************************************************/
int inputInfo(personal &pe, vector<record> &re) {
    int i;
    char p;
    printf("\n请输入您的姓名(只限英文名)\n");
    scanf("%s", pe.name);
    printf("请输入您的性别(m为男性,w为女性)\n");
    scanf(" %c", &pe.sex);  // 注意这里的空格，防止读取空字符
    printf("请输入您的年龄\n");
    scanf("%f", &pe.age);
    printf("请输入您的地址(限用拼音或英文,中间加空格)\n");
    scanf("%s", pe.add);
    printf("请输入您的电话(只需要一个)\n");
    scanf("%s", pe.tel);
    printf("请输入您的余额\n");
    scanf("%f", &pe.yue);
    printf("您的个人信息已经输入完毕,下面请输入您的收支记录\n");
    for (i = 0; p != 'n' && i < N; i++) {
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
        scanf("%f", &rec.money);
        printf("请输入原因(只限拼音或者英文)\n");
        scanf("%s", rec.reason);

        re.push_back(rec);

        if (i < N) {
            printf("是否还要继续输入y/n\n");
            scanf(" %c", &p);  // 注意这里的空格，防止读取空字符
        }
    }
    return re.size();
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
                scanf("%f", &rec.money);
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
                scanf("%f", &rec.money);
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
功能: 打印收支清单
*******************************************************/
void outputInfo(const vector<record> &re) {
    printf("************************收支清单****************************\n");
    printf("日期                                                    收支\n");
    for (const auto &rec : re) {
        printf("%d.%d.%d                                              %c%f\n", rec.year, rec.month, rec.day, rec.shouzhi, rec.money);
    }
}

/************************************
总收入和支出统计
************************************/
void tongji(const vector<record> &re) {
    float s = 0, z = 0;
    for (const auto &rec : re) {
        if (rec.shouzhi == '+')
            s += rec.money;
        else
            z += rec.money;
    }
    printf("总收入=%f\n", s);
    printf("总支出=%f\n", z);
}

/****************************************************
查询个人信息以及余额
****************************************************/
void chaxun(const personal &pe, const vector<record> &re) {
    float total = 0, ye;
    for (const auto &rec : re) {
        if (rec.shouzhi == '+')
            total += rec.money;
        else
            total -= rec.money;
    }
    ye = pe.yue + total;
    printf("\n姓名)\n");
    printf("%s\n", pe.name);
    printf("性别\n");
    printf("%c\n", pe.sex);
    printf("年龄\n");
    printf("%f\n", pe.age);
    printf("地址)\n");
    printf("%s\n", pe.add);
    printf("电话\n");
    printf("%s\n", pe.tel);
    printf("余额\n");
    printf("%f\n", ye);
}



/*******************************************************
功能: 主函数
参数：无
返回值：int类型
*******************************************************/
int main() {
    personal pe;
    vector<record> re;
    int length = 0;
    int choice = 0; /* select and store menu item */
    int s = 0, arrayLength = 0;
    char password[10];

    /*====验证用户的口令，直到正确为止====*/
    do {
        printf("请输入包装盒上的密钥：\n");
        scanf("%s", password);

        s = login(password);
    } while (s == 0);

    /* 初始化数据 */
    readFromFile1(pe);
    readFromFile2(re);
    length = re.size();

    /*====根据用户的选择，执行相应的操作.====*/
    while (1) {
        displayMenu();
        printf("\n 请选择您的操作(1,2,3,4,5,6,7)：\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                length = inputInfo(pe, re);
                printf("\n个人信息输入成功\n");
                break;
            case 2:
                guanli(re);
                break;
            case 3:
                outputInfo(re);
                break;
            case 4:
                tongji(re);
                break;
            case 5:
                chaxun(pe, re);
                break;
            case 6:
                writeToFile1(pe);
                writeToFile2(re);
                break;
            case 7:
                exit(0);
                break;
        }
    }
    return 0;
}
