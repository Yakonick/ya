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
CMAKE_SOURCE_DIR = /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gxdhcfvgbhnj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gxdhcfvgbhnj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gxdhcfvgbhnj.dir/flags.make

CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.o: CMakeFiles/gxdhcfvgbhnj.dir/flags.make
CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.o -c /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj/main.cpp

CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj/main.cpp > CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.i

CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj/main.cpp -o CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.s

# Object files for target gxdhcfvgbhnj
gxdhcfvgbhnj_OBJECTS = \
"CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.o"

# External object files for target gxdhcfvgbhnj
gxdhcfvgbhnj_EXTERNAL_OBJECTS =

gxdhcfvgbhnj: CMakeFiles/gxdhcfvgbhnj.dir/main.cpp.o
gxdhcfvgbhnj: CMakeFiles/gxdhcfvgbhnj.dir/build.make
gxdhcfvgbhnj: CMakeFiles/gxdhcfvgbhnj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gxdhcfvgbhnj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gxdhcfvgbhnj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gxdhcfvgbhnj.dir/build: gxdhcfvgbhnj

.PHONY : CMakeFiles/gxdhcfvgbhnj.dir/build

CMakeFiles/gxdhcfvgbhnj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gxdhcfvgbhnj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gxdhcfvgbhnj.dir/clean

CMakeFiles/gxdhcfvgbhnj.dir/depend:
	cd /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj/cmake-build-debug /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj/cmake-build-debug /Users/yasen/Desktop/Коды/GitHub/ya/Tasks/gxdhcfvgbhnj/cmake-build-debug/CMakeFiles/gxdhcfvgbhnj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gxdhcfvgbhnj.dir/depend

