# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shajiejie/CLionProjects/SalaryManageSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shajiejie/CLionProjects/SalaryManageSystem/build

# Include any dependencies generated for this target.
include CMakeFiles/SalaryManageSystem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SalaryManageSystem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SalaryManageSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SalaryManageSystem.dir/flags.make

CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.o: CMakeFiles/SalaryManageSystem.dir/flags.make
CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.o: /Users/shajiejie/CLionProjects/SalaryManageSystem/src/SalaryManageSystemNew.cpp
CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.o: CMakeFiles/SalaryManageSystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shajiejie/CLionProjects/SalaryManageSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.o -MF CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.o.d -o CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.o -c /Users/shajiejie/CLionProjects/SalaryManageSystem/src/SalaryManageSystemNew.cpp

CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shajiejie/CLionProjects/SalaryManageSystem/src/SalaryManageSystemNew.cpp > CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.i

CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shajiejie/CLionProjects/SalaryManageSystem/src/SalaryManageSystemNew.cpp -o CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.s

# Object files for target SalaryManageSystem
SalaryManageSystem_OBJECTS = \
"CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.o"

# External object files for target SalaryManageSystem
SalaryManageSystem_EXTERNAL_OBJECTS =

output/SalaryManageSystem: CMakeFiles/SalaryManageSystem.dir/src/SalaryManageSystemNew.cpp.o
output/SalaryManageSystem: CMakeFiles/SalaryManageSystem.dir/build.make
output/SalaryManageSystem: output/libOpenXLSX.a
output/SalaryManageSystem: CMakeFiles/SalaryManageSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/shajiejie/CLionProjects/SalaryManageSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable output/SalaryManageSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SalaryManageSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SalaryManageSystem.dir/build: output/SalaryManageSystem
.PHONY : CMakeFiles/SalaryManageSystem.dir/build

CMakeFiles/SalaryManageSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SalaryManageSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SalaryManageSystem.dir/clean

CMakeFiles/SalaryManageSystem.dir/depend:
	cd /Users/shajiejie/CLionProjects/SalaryManageSystem/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shajiejie/CLionProjects/SalaryManageSystem /Users/shajiejie/CLionProjects/SalaryManageSystem /Users/shajiejie/CLionProjects/SalaryManageSystem/build /Users/shajiejie/CLionProjects/SalaryManageSystem/build /Users/shajiejie/CLionProjects/SalaryManageSystem/build/CMakeFiles/SalaryManageSystem.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SalaryManageSystem.dir/depend

