/*
 * Created by 沙杰杰 on 2024/5/22.
 * 文件读取写入以及控制台信息的打印
 */
#include "data_define.cpp"
#include <OpenXLSX.hpp>
#include <vector>
#include <string>


/*******************************************************
功能: 读取文件中的存储信息
*******************************************************/

void readFromFile1(readpersonal &pe) {
    XLDocument doc;
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
    XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");


        re.year = wks.cell(row, 1).value().get<int>();
        re.month = wks.cell(row, 2).value().get<int>();
        re.day = wks.cell(row, 3).value().get<int>();
        re.shouzhi = wks.cell(row, 4).value().get<std::string>();
        re.money = wks.cell(row, 5).value().get<int>();
        re.reason = wks.cell(row, 6).value().get<std::string>();

        doc.close();

}
/*******************************************************
功能: 结构体数组中的学生信息输出到文件
*******************************************************/

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

/*******************************************************
功能: 按序打印文件中存储的信息到控制台
*******************************************************/

void printPersonal(){

    //读取文件
    readpersonal pe_read;
    readFromFile1(pe_read);

    // Print the personal data
    std::cout << "Personal Data:" << std::endl;
    std::cout << "Name: " << pe_read.name << "   ";
    std::cout << "Sex: " << pe_read.sex << "   ";
    std::cout << "Age: " << pe_read.age << "   ";
    std::cout << "Address: " << pe_read.add << "   ";
    std::cout << "Telephone: " << pe_read.tel << "   ";
    std::cout << "Balance: " << pe_read.yue << "   ";

}

void printRecord(int row,int count){


    XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");


    while (count < MAX_RECORDS) {
        auto cell = wks.cell(row, 1);
        if (cell.value().type() == XLValueType::Integer) {
            int yearValue = cell.value().get<int>();
            if (yearValue != 0) {
                readrecord re_read;
                readFromFile2(row, re_read);
                row++;
                count++;

                std::cout << "\nRecords Data:" << std::endl;
                std::cout << "year " << re_read.year << "    ";
                std::cout << "month " << re_read.month << "    ";
                std::cout << "day " << re_read.day << "   ";
                std::cout << "shouzhi " << re_read.shouzhi << "   ";
                std::cout << "money " << re_read.money << "   ";
                std::cout << "reason " << re_read.reason << "   ";
            } else {
                break; // Stop if the year value is 0 (or any other sentinel value indicating end of data)
            }
        } else {
            break; // Stop if the cell is not an integer
        }
    }
}

