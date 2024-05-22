//
// Created by 沙杰杰 on 2024/5/22.
//
#include <OpenXLSX.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace OpenXLSX;
using namespace std;

struct personal {
    std::string name;
    char sex;
    int age;
    std::string add;
    std::string tel;
    double yue;
};

struct record {
    int year;
    int month;
    int day;
    char shouzhi;
    double money;
    std::string reason;
};

const std::string FILENAME1 = "/Users/shajiejie/Desktop/personal.xlsx";
const std::string FILENAME2 = "/Users/shajiejie/Desktop/money.xlsx";

void writeToFile1(const personal &pe) {
    XLDocument doc;
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
    doc.open(FILENAME1);
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

int main() {
    // 测试用例
    personal pe = {"张三", 'M', 30, "某街道", "123456789", 1000.50};
    writeToFile1(pe);

    vector<record> re = {
            {2023, 5, 21, '+', 5000.00, "工资"},
            {2023, 5, 22, '-', 1500.00, "购物"}
    };
    writeToFile2(re);

    return 0;
}
