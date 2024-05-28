//
// Created by 沙杰杰 on 2024/5/28.
//
#include "typecheck.h"  // 包含 typecheck 类的定义
#include "data_define.h"

int main() {
    // 创建和打开 Excel 文档对象
    XLDocument doc;
    doc.open(FILENAME2);  // 假设 FILENAME2 是包含 "Records" 工作表的 Excel 文件的路径

    // 获取 "Records" 工作表
    auto wks = doc.workbook().worksheet("Records");

    // 获取 E3 单元格
    auto cell = wks.cell("E4");

    // 创建 typecheck 类的实例
    typecheck checker;

    // 使用 typecheck 类的方法检查并打印单元格类型
    checker.readGeneralCell(cell);

    // 关闭文档
    doc.close();

    return 0;
}
