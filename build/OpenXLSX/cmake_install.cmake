# Install script for directory: /Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES "/Users/shajiejie/CLionProjects/SalaryManageSystem/build/OpenXLSX/OpenXLSX-Exports.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/IZipArchive.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLCell.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLCellIterator.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLCellRange.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLCellReference.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLCellValue.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLColor.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLColumn.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLCommandQuery.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLConstants.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLContentTypes.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLDateTime.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLDocument.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLException.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLFormula.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLIterator.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLProperties.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLRelationships.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLRow.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLRowData.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLSharedStrings.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLSheet.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLWorkbook.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLXmlData.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLXmlFile.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLXmlParser.hpp"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/headers/XLZipArchive.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX" TYPE FILE FILES "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/OpenXLSX.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "lib" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/shajiejie/CLionProjects/SalaryManageSystem/build/output/libOpenXLSX.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOpenXLSX.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOpenXLSX.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOpenXLSX.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/OpenXLSX/OpenXLSXConfig.cmake"
    "/Users/shajiejie/CLionProjects/SalaryManageSystem/build/OpenXLSX/OpenXLSX/OpenXLSXConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake"
         "/Users/shajiejie/CLionProjects/SalaryManageSystem/build/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "/Users/shajiejie/CLionProjects/SalaryManageSystem/build/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "/Users/shajiejie/CLionProjects/SalaryManageSystem/build/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets-noconfig.cmake")
  endif()
endif()

