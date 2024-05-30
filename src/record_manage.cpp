//
// Created by 沙杰杰 on 2024/5/30.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <OpenXLSX.hpp>
#include "data_define.h"
#include "record_manage.h"
#include <vector>


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
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");
    for (int row = startRow; row <= endRow; ++row) {
        for (int col = startCol; col <= endCol; ++col) {
            // 清空单元格
            wks.cell(OpenXLSX::XLCellReference(row, col)).value() = "";
        }
    }
}

std::vector<readrecord> readAllRecords() {
    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");

    std::vector<readrecord> records;
    int row = 2;  // 假设第一行是标题行
    while (wks.cell(row, 1).value().type() != OpenXLSX::XLValueType::Empty) {
        readrecord re;
        re.year = wks.cell(row, 1).value().get<int>();
        re.month = wks.cell(row, 2).value().get<int>();
        re.day = wks.cell(row, 3).value().get<int>();
        re.shouzhi = wks.cell(row, 4).value().get<std::string>();
        re.money = wks.cell(row, 5).value().get<double>();
        re.reason = wks.cell(row, 6).value().get<std::string>();
        records.push_back(re);
        row++;
    }

    doc.close();
    return records;
}

void deleteAndRewriteRecords(int recordToDelete) {

    // 重新写入剩余的记录
    OpenXLSX::XLDocument doc;
    doc.open(FILENAME2);
    auto wks = doc.workbook().worksheet("Records");

    auto records = readAllRecords();

    if (recordToDelete < 1 || recordToDelete >= records.size()) {
        std::cerr << "Invalid record number to delete. Valid range is 1 to " << records.size() - 1 << std::endl;
        return;
    }

    // 删除指定记录及其后续记录
    records.erase(records.begin() + recordToDelete - 1, records.end());

    // 清空可能包含过时数据的现有单元格
    int lastRow = getLastRecordRow();
    clearCells( 2, lastRow, 1, 6);  // 假设数据从第2行开始且有6列

    // 重写标题行
    wks.cell("A1").value() = "年";
    wks.cell("B1").value() = "月";
    wks.cell("C1").value() = "日";
    wks.cell("D1").value() = "收支";
    wks.cell("E1").value() = "数额";
    wks.cell("F1").value() = "原因";

    // 重新写入数据
    int rowIndex = 2;
    for (const auto &re : records) {
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
