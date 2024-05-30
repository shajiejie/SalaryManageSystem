/*
 * data_define.h
 * Created by 沙杰杰 on 2024/5/27.
 * 结构体定义及各种传输数据的定义
 */
#ifndef DATA_DEFINE_H
#define DATA_DEFINE_H

#include <string>
#include <vector>
#include "data_define.h"
#include <OpenXLSX.hpp>

#define N 30

// Define the maximum number of records to read
const int MAX_RECORDS = 100;

const std::string FILENAME1 = "/Users/shajiejie/Desktop/personal.xlsx";
const std::string FILENAME2 = "/Users/shajiejie/Desktop/money.xlsx";


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
#endif // DATA_DEFINE_H
