set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(SalaryManageSystem SalaryManageSystemNew.cpp)

include_directories(OpenXLSX)

# 查找 OpenXLSX 包
find_package(OpenXLSX REQUIRED)

# 链接 OpenXLSX 库
target_link_libraries(SalaryManageSystem OpenXLSX::OpenXLSX)