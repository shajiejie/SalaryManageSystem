//
// Created by 沙杰杰 on 2024/5/23.
//

#ifndef SALARYMANAGESYSTEM_TYPECHECK_H
#define SALARYMANAGESYSTEM_TYPECHECK_H

#include <OpenXLSX.hpp>
#include <iostream>
#include <variant>

using namespace OpenXLSX;

class typecheck {
public:
    void readGeneralCell(const XLCell& cell) {
        switch (cell.value().type()) {
            case XLValueType::String: {
                std::string strValue = cell.value().get<std::string>();
                std::cout << "String: " << strValue << std::endl;
                break;
            }
            case XLValueType::Integer: {
                int intValue = cell.value().get<int>();
                std::cout << "Integer: " << intValue << std::endl;
                break;
            }
            case XLValueType::Float: {
                double floatValue = cell.value().get<double>();
                std::cout << "Float: " << floatValue << std::endl;
                break;
            }
            case XLValueType::Boolean: {
                bool boolValue = cell.value().get<bool>();
                std::cout << "Boolean: " << std::boolalpha << boolValue << std::endl;
                break;
            }
            case XLValueType::Error: {
                std::cout << "Error in cell" << std::endl;
                break;
            }
            default: {
                std::cout << "Unknown type" << std::endl;
                break;
            }
        }
    }
};

#endif // SALARYMANAGESYSTEM_TYPECHECK_H
