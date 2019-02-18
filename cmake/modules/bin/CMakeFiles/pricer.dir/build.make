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
CMAKE_BINARY_DIR = /Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules

# Include any dependencies generated for this target.
include bin/CMakeFiles/pricer.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/pricer.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/pricer.dir/flags.make

bin/CMakeFiles/pricer.dir/pricer.cpp.o: bin/CMakeFiles/pricer.dir/flags.make
bin/CMakeFiles/pricer.dir/pricer.cpp.o: ../../src/bin/pricer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/pricer.dir/pricer.cpp.o"
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules/bin && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pricer.dir/pricer.cpp.o -c /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/bin/pricer.cpp

bin/CMakeFiles/pricer.dir/pricer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pricer.dir/pricer.cpp.i"
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules/bin && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/bin/pricer.cpp > CMakeFiles/pricer.dir/pricer.cpp.i

bin/CMakeFiles/pricer.dir/pricer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pricer.dir/pricer.cpp.s"
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules/bin && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/bin/pricer.cpp -o CMakeFiles/pricer.dir/pricer.cpp.s

# Object files for target pricer
pricer_OBJECTS = \
"CMakeFiles/pricer.dir/pricer.cpp.o"

# External object files for target pricer
pricer_EXTERNAL_OBJECTS =

bin/pricer: bin/CMakeFiles/pricer.dir/pricer.cpp.o
bin/pricer: bin/CMakeFiles/pricer.dir/build.make
bin/pricer: lib/libcra.a
bin/pricer: lib/libalgorithms.a
bin/pricer: /opt/local/lib/libQuantLib.dylib
bin/pricer: /opt/local/lib/libboost_filesystem-mt.dylib
bin/pricer: /opt/local/lib/libboost_system-mt.dylib
bin/pricer: bin/CMakeFiles/pricer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pricer"
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pricer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/pricer.dir/build: bin/pricer

.PHONY : bin/CMakeFiles/pricer.dir/build

bin/CMakeFiles/pricer.dir/clean:
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules/bin && $(CMAKE_COMMAND) -P CMakeFiles/pricer.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/pricer.dir/clean

bin/CMakeFiles/pricer.dir/depend:
	cd /Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ETHIY/Workspace/Projects/houda/cra_pricer /Users/ETHIY/Workspace/Projects/houda/cra_pricer/src/bin /Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules /Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules/bin /Users/ETHIY/Workspace/Projects/houda/cra_pricer/cmake/modules/bin/CMakeFiles/pricer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/pricer.dir/depend

