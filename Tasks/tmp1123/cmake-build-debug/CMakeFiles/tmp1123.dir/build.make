# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tmp1123.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tmp1123.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tmp1123.dir/flags.make

CMakeFiles/tmp1123.dir/main.cpp.o: CMakeFiles/tmp1123.dir/flags.make
CMakeFiles/tmp1123.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tmp1123.dir/main.cpp.o"
	/usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tmp1123.dir/main.cpp.o -c /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123/main.cpp

CMakeFiles/tmp1123.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tmp1123.dir/main.cpp.i"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123/main.cpp > CMakeFiles/tmp1123.dir/main.cpp.i

CMakeFiles/tmp1123.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tmp1123.dir/main.cpp.s"
	/usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123/main.cpp -o CMakeFiles/tmp1123.dir/main.cpp.s

# Object files for target tmp1123
tmp1123_OBJECTS = \
"CMakeFiles/tmp1123.dir/main.cpp.o"

# External object files for target tmp1123
tmp1123_EXTERNAL_OBJECTS =

tmp1123: CMakeFiles/tmp1123.dir/main.cpp.o
tmp1123: CMakeFiles/tmp1123.dir/build.make
tmp1123: CMakeFiles/tmp1123.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tmp1123"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tmp1123.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tmp1123.dir/build: tmp1123

.PHONY : CMakeFiles/tmp1123.dir/build

CMakeFiles/tmp1123.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tmp1123.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tmp1123.dir/clean

CMakeFiles/tmp1123.dir/depend:
	cd /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123 /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123 /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123/cmake-build-debug /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123/cmake-build-debug /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/tmp1123/cmake-build-debug/CMakeFiles/tmp1123.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tmp1123.dir/depend

