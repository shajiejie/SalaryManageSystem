cmake_minimum_required(VERSION 3.15)
project(SalaryManageSystem)

set(CMAKE_CXX_STANDARD 17)

# Set the build output location to a common directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

add_subdirectory(OpenXLSX)

add_executable(SalaryManageSystem
#        src/SalaryManageSystemNew.cpp
#        src/file_action.cpp
#        src/data_define.h
#        src/file_action.h
#        src/balance_calculate.cpp
#        src/balance_calculate.h
#        src/file_action.cpp
#        src/record_manage.cpp
#        src/record_manage.h
        src/test.cpp
        src/record_manage.cpp
        #        src/typecheck.h
#        src/celltypecheck.cpp
)

target_link_libraries(SalaryManageSystem OpenXLSX::OpenXLSX)

