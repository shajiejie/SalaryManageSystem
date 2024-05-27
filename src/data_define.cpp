/*
 * Created by 沙杰杰 on 2024/5/27.
 * 结构体定义及各种传输数据的定义
 */
#pragma once
#include <OpenXLSX.hpp>
#include <vector>
#include <string>

// Define the maximum number of records to read
const int MAX_RECORDS = 100;

const std::string FILENAME1 = "/Users/shajiejie/Desktop/personal.xlsx";
const std::string FILENAME2 = "/Users/shajiejie/Desktop/money.xlsx";


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
    int money;
    std::string reason;
};