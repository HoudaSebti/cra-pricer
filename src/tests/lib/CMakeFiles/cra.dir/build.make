# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ETHIY/Workspace/Projects/houda/cra_pricer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests

# Include any dependencies generated for this target.
include lib/CMakeFiles/cra.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/cra.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/cra.dir/flags.make

lib/CMakeFiles/cra.dir/callable_range_accrual.cpp.o: lib/CMakeFiles/cra.dir/flags.make
lib/CMakeFiles/cra.dir/callable_range_accrual.cpp.o: ../lib/callable_range_accrual.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/cra.dir/callable_range_accrual.cpp.o"
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cra.dir/callable_range_accrual.cpp.o -c /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/lib/callable_range_accrual.cpp

lib/CMakeFiles/cra.dir/callable_range_accrual.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cra.dir/callable_range_accrual.cpp.i"
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/lib/callable_range_accrual.cpp > CMakeFiles/cra.dir/callable_range_accrual.cpp.i

lib/CMakeFiles/cra.dir/callable_range_accrual.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cra.dir/callable_range_accrual.cpp.s"
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/lib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/lib/callable_range_accrual.cpp -o CMakeFiles/cra.dir/callable_range_accrual.cpp.s

# Object files for target cra
cra_OBJECTS = \
"CMakeFiles/cra.dir/callable_range_accrual.cpp.o"

# External object files for target cra
cra_EXTERNAL_OBJECTS =

lib/libcra.a: lib/CMakeFiles/cra.dir/callable_range_accrual.cpp.o
lib/libcra.a: lib/CMakeFiles/cra.dir/build.make
lib/libcra.a: lib/CMakeFiles/cra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcra.a"
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/lib && $(CMAKE_COMMAND) -P CMakeFiles/cra.dir/cmake_clean_target.cmake
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/cra.dir/build: lib/libcra.a

.PHONY : lib/CMakeFiles/cra.dir/build

lib/CMakeFiles/cra.dir/clean:
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/lib && $(CMAKE_COMMAND) -P CMakeFiles/cra.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/cra.dir/clean

lib/CMakeFiles/cra.dir/depend:
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ETHIY/Workspace/Projects/houda/cra_pricer /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/lib /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/lib /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/tests/lib/CMakeFiles/cra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/cra.dir/depend

