/*
 * Created by 沙杰杰 on 2024/5/22.
 * 余额修改及总收入支出计算
 */
#include "data_define.h"
#include "balance_calculate.h"
#include <cmath>
#include <OpenXLSX.hpp>
#include <string>

using namespace OpenXLSX;
using namespace std;

// 用于四舍五入到指定的小数位数
double roundToTwoDecimals(double value) {
    return std::round(value * 100.0) / 100.0;
}

double disburseCalculate(int row, int count) {

    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2); // 打开 Excel 文档
    auto wks = doc.workbook().worksheet("Records"); // 访问特定的工作表


    double disbursetotal = 0; // 初始化累加器

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
                double amount = numbercell.value().get<double>();
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

double incomeCalculate(int row, int count){

    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2); // 打开 Excel 文档
    auto wks = doc.workbook().worksheet("Records"); // 访问特定的工作表

    double incometotal = 0;

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
                double amount = numbercell.value().get<double>();
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
        double amount = recordsSheet.cell(XLCellReference(row, 5)).value().get<double>();

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
