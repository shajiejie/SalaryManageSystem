/*
 * file_action.h
 * Created by 沙杰杰 on 2024/5/23.
 * xlsx文件操作类（读取，写入，修改余额）
 */

#include <vector>
#include "data_define.h"
#ifndef SALARYMANAGESYSTEM_FILE_ACTION_H
#define SALARYMANAGESYSTEM_FILE_ACTION_H

void readFromFile1(readpersonal &pe);

void readFromFile2(int row, readrecord &re);

void writeToFile1(const personal &pe);

void writeToFile2(const std::vector<record> &re);

void printPersonal();

void printRecord(int row,int count);

#endif //SALARYMANAGESYSTEM_FILE_ACTION_H
