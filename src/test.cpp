//
// Created by 沙杰杰 on 2024/5/29.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <iomanip>
#include <OpenXLSX.hpp>
#include <vector>

#define N 30

const int MAX_RECORDS = 100;

const std::string FILENAME1 = "/Users/shajiejie/Desktop/personal.xlsx";
const std::string FILENAME2 = "/Users/shajiejie/Desktop/money.xlsx";

using namespace OpenXLSX;
using namespace std;

struct personal {
    char name[10];         /* 姓名 */
    char sex;              /* 性别 */
    int age;             /* 年龄 */
    char add[40];          /* 地址 */
    char tel[20];          /* 电话 */
    double yue;             /* 余额 */
};

struct record {
    int year;
    int month;
    int day;
    char shouzhi;
    double money;
    char reason[50];
};

struct readpersonal {
    std::string name;
    std::string sex;
    int age;
    std::string add;
    std::string tel;
    double yue;
};

struct readrecord {
    int year;
    int month;
    int day;
    std::string shouzhi;
    double money;
    std::string reason;
};

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


void writeToFile1(const personal &pe) {
    OpenXLSX::XLDocument doc;
    doc.open(FILENAME1);
    auto wks = doc.workbook().worksheet("Personal");

    wks.cell("A1").value() = "姓名";
    wks.cell("B1").value() = "性别";
    wks.cell("C1").value() = "年龄";
    wks.cell("D1").value() = "地址";
    wks.cell("E1").value() = "电话";
    wks.cell("F1").value() = "余额";

    wks.cell("A2").value() = pe.name;
    wks.cell("B2").value() = std::string(1, pe.sex);  // 确保类型匹配
    wks.cell("C2").value() = pe.age;
    wks.cell("D2").value() = pe.add;
    wks.cell("E2").value() = pe.tel;
    wks.cell("F2").value() = pe.yue;

    doc.save();
    doc.close();
}

void writeToFile2(const vector<record> &re) {
    XLDocument doc;
    doc.open(FILENAME2);
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
        wks.cell(i + 2, 4).value() = std::string(1, re[i].shouzhi);  // 确保类型匹配
        wks.cell(i + 2, 5).value() = re[i].money;
        wks.cell(i + 2, 6).value() = re[i].reason;
    }

    doc.save();
    doc.close();
}
void readFromFile1(readpersonal &pe) {
    OpenXLSX::XLDocument doc;
    doc.open(FILENAME1);

    auto wks = doc.workbook().worksheet("Personal");

    pe.name = wks.cell("A2").value().get<std::string>();
    pe.sex = wks.cell("B2").value().get<std::string>();
    pe.age = wks.cell("C2").value().get<int>();
    pe.add = wks.cell("D2").value().get<std::string>();
    pe.tel = wks.cell("E2").value().get<std::string>();
    pe.yue = wks.cell("F2").value().get<double>();

    doc.close();
}

void readFromFile2(int row, readrecord &re) {
    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");


    re.year = wks.cell(row, 1).value().get<int>();
    re.month = wks.cell(row, 2).value().get<int>();
    re.day = wks.cell(row, 3).value().get<int>();
    re.shouzhi = wks.cell(row, 4).value().get<std::string>();
    re.money = wks.cell(row, 5).value().get<double>();
    re.reason = wks.cell(row, 6).value().get<std::string>();

    doc.close();

}
/*******************************************************
功能: 按序打印文件中存储的信息到控制台
*******************************************************/

void printPersonal(){

    //读取文件
    readpersonal pe_read;
    readFromFile1(pe_read);

    // Print the personal data
    std::cout << "                            Personal Data:           " << std::endl;
    std::cout << "Name: " << pe_read.name << "   ";
    std::cout << "Sex: " << pe_read.sex << "   ";
    std::cout << "Age: " << pe_read.age << "   ";
    std::cout << "Address: " << pe_read.add << "   ";
    std::cout << "Telephone: " << pe_read.tel << "   ";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Balance: " << pe_read.yue << std::endl;

}

void printRecord(int row,int count){


    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");

    printf("*******************************收支清单*************************************");
    std::cout << "\n                             Records Data :          " << std::endl;
    while (count < MAX_RECORDS) {
        auto cell = wks.cell(row, 1);
        if (cell.value().type() == XLValueType::Integer) {
            int yearValue = cell.value().get<int>();
            if (yearValue != 0) {
                readrecord re_read;
                readFromFile2(row, re_read);
                row++;
                count++;

                std::cout << "year " << re_read.year << "    ";
                std::cout << "month " << re_read.month << "    ";
                std::cout << "day " << re_read.day << "   ";
                std::cout << "shouzhi " << re_read.shouzhi << "   ";
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "money " << re_read.money << "   ";
                std::cout << "reason " << re_read.reason << std::endl;
            } else {
                break; // Stop if the year value is 0 (or any other sentinel value indicating end of data)
            }
        } else {
            break; // Stop if the cell is not an integer
        }
    }
}
// Prototype the functions used

// 用于四舍五入到指定的小数位数
double roundToTwoDecimals(double value) {
    return std::round(value * 100.0) / 100.0;
}

float disburseCalculate(int row, int count) {

    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2); // 打开 Excel 文档
    auto wks = doc.workbook().worksheet("Records"); // 访问特定的工作表


    float disbursetotal = 0; // 初始化累加器

    while (count < MAX_RECORDS) {
        auto yearcell = wks.cell(row, 1);
        auto symbolcell = wks.cell(row, 4);
        auto numbercell = wks.cell(row, 5);

        if (yearcell.value().type() == XLValueType::Integer) {
            int year = yearcell.value().get<int>();
            if (year == 0) {
                break; // 如果年份为0，则假设为数据结束标志
            }

            string symbol = symbolcell.value().get<std::string>();
            if (symbol == "-") {
                float amount = numbercell.value().get<float>();
                disbursetotal += amount; // 累加支出
            }

            row++; // 移动到下一行
            count++; // 增加计数
        } else {
            break; // 如果年份单元格不是整数类型，则停止
        }
    }

    doc.close(); // 关闭文档
    return disbursetotal;
}

float incomeCalculate(int row, int count){

    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2); // 打开 Excel 文档
    auto wks = doc.workbook().worksheet("Records"); // 访问特定的工作表

    float incometotal = 0;

    while (count < MAX_RECORDS) {
        auto yearcell = wks.cell(row, 1);
        auto symbolcell = wks.cell(row, 4);
        auto numbercell = wks.cell(row, 5);

        if (yearcell.value().type() == XLValueType::Integer) {
            int year = yearcell.value().get<int>();
            if (year == 0) {
                break; // 如果年份为0，则假设为数据结束标志
            }

            string symbol = symbolcell.value().get<std::string>();
            if (symbol == "+") {
                float amount = numbercell.value().get<float>();
                incometotal += amount; // 累加收入
            }

            row++; // 移动到下一行
            count++; // 增加计数
        } else {
            break; // 如果年份单元格不是整数类型，则停止
        }
    }

    doc.close(); // 关闭文档
    return incometotal;
}

void balance_change(int row) {

    // 打开个人信息文件以获取当前余额
    OpenXLSX::XLDocument docPersonal;
    docPersonal.open(FILENAME1);
    auto personalSheet = docPersonal.workbook().worksheet("Personal");
    double balanceChange = personalSheet.cell("F2").value().get<double>();
    docPersonal.close();  // 获取余额后关闭文件

    // 打开包含记录的文件
    OpenXLSX::XLDocument docRecords;
    docRecords.open(FILENAME2);
    auto recordsSheet = docRecords.workbook().worksheet("Records");


    while (true) {
        auto yearCell = recordsSheet.cell(XLCellReference(row, 1));
        if (yearCell.value().type() != XLValueType::Integer || yearCell.value().get<int>() == 0) {
            break;  // 假设年份列为空或0表示记录结束
        }

        string type = recordsSheet.cell(XLCellReference(row, 4)).value().get<std::string>();
        float amount = recordsSheet.cell(XLCellReference(row, 5)).value().get<float>();

        // 根据收支类型调整余额
        if (type == "+") {
            balanceChange += amount;
        } else if (type == "-") {
            balanceChange -= amount;
        }

        row++;
    }

    docRecords.close();  // 关闭记录文件

    // 再次打开个人信息文件以更新余额
    docPersonal.open(FILENAME1);
    personalSheet = docPersonal.workbook().worksheet("Personal");
    personalSheet.cell("F2").value() = roundToTwoDecimals(balanceChange);  // 更新余额

    docPersonal.save();  // 保存更改
    docPersonal.close();  // 关闭文件
}

int getLastRecordRow() {
    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");

    int lastRow = 1; // 初始化为1，假设至少有标题行
    for (int i = 2; i < MAX_RECORDS + 2; i++) { // 假设最多有MAX_RECORDS条记录，从第2行开始检查
        auto cell = wks.cell(i, 1); // 假设年份在第一列
        if (cell.value().type() != OpenXLSX::XLValueType::Empty && cell.value().type() == OpenXLSX::XLValueType::Integer) {
            lastRow = i; // 更新最后一个有数据的行号
        } else {
            break; // 遇到空单元格或非整数值时停止
        }
    }

    doc.close();
    return lastRow;
}

void clearCells(int startRow, int endRow, int startCol, int endCol) {
    OpenXLSX::XLDocument doc;
    try {
        doc.open(FILENAME2);
        auto wks = doc.workbook().worksheet("Records");
        for (int row = startRow; row <= endRow; row++) {
            for (int col = startCol; col <= endCol; col++) {
                wks.cell(row, col).value() = "";
            }
        }
        doc.save();
        doc.close();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

//读取全部数据
std::vector<readrecord> readAllRecords() {
    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");

    std::vector<readrecord> allrecords;
    int row = 2;  // 假设第一行是标题行
    while (wks.cell(row, 1).value().type() != OpenXLSX::XLValueType::Empty) {
        readrecord re;
        re.year = wks.cell(row, 1).value().get<int>();
        re.month = wks.cell(row, 2).value().get<int>();
        re.day = wks.cell(row, 3).value().get<int>();
        re.shouzhi = wks.cell(row, 4).value().get<std::string>();
        re.money = wks.cell(row, 5).value().get<double>();
        re.reason = wks.cell(row, 6).value().get<std::string>();
        allrecords.push_back(re);
        row++;
    }

    doc.close();
    return allrecords;
}

//读取被删除行后的全部数据
std::vector<readrecord> readPartRecords(int deleterow) {
    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");

    std::vector<readrecord> partrecords;
    int partrow = deleterow + 2;
    int lastRow = getLastRecordRow();
    while (wks.cell(partrow , 1).value().type() != OpenXLSX::XLValueType::Empty && partrow <= lastRow ) {
        readrecord re;
        re.year = wks.cell(partrow , 1).value().get<int>();
        re.month = wks.cell(partrow , 2).value().get<int>();
        re.day = wks.cell(partrow , 3).value().get<int>();
        re.shouzhi = wks.cell(partrow , 4).value().get<std::string>();
        re.money = wks.cell(partrow , 5).value().get<double>();
        re.reason = wks.cell(partrow , 6).value().get<std::string>();
        partrecords.push_back(re);
        partrow ++;
    }

    doc.close();
    return partrecords;
}

void deleteAndRewriteRecords(int recordToDelete) {

    // 重新写入剩余的记录
    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");

    auto partrecords = readPartRecords(recordToDelete);

    if (recordToDelete < 1 || recordToDelete >= partrecords.size()) {
        std::cerr << "Invalid record number to delete. Valid range is 1 to " << partrecords.size() - 1 << std::endl;
        return;
    }

    // 清空可能包含过时数据的现有单元格
    int lastRow = getLastRecordRow();

    clearCells( recordToDelete + 1, lastRow, 1, 6);

    // 重写标题行
    wks.cell("A1").value() = "年";
    wks.cell("B1").value() = "月";
    wks.cell("C1").value() = "日";
    wks.cell("D1").value() = "收支";
    wks.cell("E1").value() = "数额";
    wks.cell("F1").value() = "原因";

    // 重新写入数据
    int rowIndex = recordToDelete + 1;
    for (const auto &re : partrecords) {
        wks.cell(rowIndex, 1).value() = re.year;
        wks.cell(rowIndex, 2).value() = re.month;
        wks.cell(rowIndex, 3).value() = re.day;
        wks.cell(rowIndex, 4).value() = re.shouzhi;
        wks.cell(rowIndex, 5).value() = re.money;
        wks.cell(rowIndex, 6).value() = re.reason;
        rowIndex++;
    }

    doc.save();
    doc.close();
}

void record_change(int recordIndex) {
    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");

    if (recordIndex < 1 || recordIndex > getLastRecordRow() - 1) {
        std::cerr << "Record index out of range." << std::endl;
        doc.close();
        return;
    }

    // 获取用户输入新记录
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


    // 写入新记录到指定行
    int row = recordIndex + 1; // 标题行是第1行
    wks.cell(row, 1).value() = rec.year;;
    wks.cell(row, 2).value() = rec.month;
    wks.cell(row, 3).value() = rec.day;
    wks.cell(row, 4).value() = rec.shouzhi;
    wks.cell(row, 5).value() = rec.money;
    wks.cell(row, 6).value() = rec.reason;

    doc.save();
    doc.close();
}

int main() {
//    int row = 2;
//    int count = 0;
//
//    personal pe;
//    std::vector<record> records;
//
//    readpersonal pe_read;
//    readrecord re_read;
//
//
//    //Function to add personal details
//    add_personal(pe);
//
//    // Function to add financial records
//    add_record(records);
//
//    // Write personal information to a file
//    writeToFile1(pe);
//
//    // Write financial records to a file
//    writeToFile2(records);
//
//    readFromFile1(pe_read);
//
//    readFromFile2(row,re_read);
//
//    printPersonal();
//
//    printRecord(row,count);
//
//    double disbursetotal = disburseCalculate(row, 0);
//    double incometotal = incomeCalculate(row, 0);
//
//    cout << "Total income: " << disbursetotal << endl; // 输出总支出
//    cout << "Total income: " << incometotal << endl; // 输出总收入
//
//    balance_change(row);
//
//    readFromFile1(pe_read);
//    printPersonal();

      int lastnumber  = getLastRecordRow();
      cout << "lastnumber: " << lastnumber << endl;

      deleteAndRewriteRecords(2);

    auto allrecords = readAllRecords();  // 获取所有记录

    // 打印每条记录
    for (const auto& record : allrecords) {
        std::cout << "Year: " << record.year
                  << ", Month: " << record.month
                  << ", Day: " << record.day
                  << ", ShouZhi: " << record.shouzhi
                  << std::fixed << std::setprecision(2)
                  << ", Money: " << record.money
                  << ", Reason: " << record.reason << std::endl;
    }
    std::cout << "Testing completed.\n";

//    auto partrecords = readPartRecords(2);  // 获取所有记录
//
//     //打印部分记录
//    for (const auto& record : partrecords) {
//        std::cout << "Year: " << record.year
//                  << ", Month: " << record.month
//                  << ", Day: " << record.day
//                  << ", ShouZhi: " << record.shouzhi
//                  << std::fixed << std::setprecision(2)
//                  << ", Money: " << record.money
//                  << ", Reason: " << record.reason << std::endl;
//    }

//    clearCells(3,8,1,6);




//    std::cout << "Deleting and rewriting records...\n";
//    deleteAndRewriteRecords(2); // 假设我们要删除第3条记录

    // 测试修改记录的功能
//    std::cout << "Changing a record...\n";
//    record_change(3); // 假设我们要修改第3条记录

    // 可以添加更多的测试功能调用
    std::cout << "Testing completed.\n";


    std::cout << "Data entry and saving complete. Check the Excel files for output." << std::endl;

    return 0;
}
