# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liu/my_progs/lintcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liu/my_progs/lintcode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/many_cpu.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/many_cpu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/many_cpu.dir/flags.make

CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o: CMakeFiles/many_cpu.dir/flags.make
CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o: ../many_cpu/many_cpu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liu/my_progs/lintcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o -c /home/liu/my_progs/lintcode/many_cpu/many_cpu.cpp

CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liu/my_progs/lintcode/many_cpu/many_cpu.cpp > CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.i

CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liu/my_progs/lintcode/many_cpu/many_cpu.cpp -o CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.s

CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o.requires:

.PHONY : CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o.requires

CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o.provides: CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o.requires
	$(MAKE) -f CMakeFiles/many_cpu.dir/build.make CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o.provides.build
.PHONY : CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o.provides

CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o.provides.build: CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o


# Object files for target many_cpu
many_cpu_OBJECTS = \
"CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o"

# External object files for target many_cpu
many_cpu_EXTERNAL_OBJECTS =

many_cpu: CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o
many_cpu: CMakeFiles/many_cpu.dir/build.make
many_cpu: CMakeFiles/many_cpu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liu/my_progs/lintcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable many_cpu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/many_cpu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/many_cpu.dir/build: many_cpu

.PHONY : CMakeFiles/many_cpu.dir/build

CMakeFiles/many_cpu.dir/requires: CMakeFiles/many_cpu.dir/many_cpu/many_cpu.cpp.o.requires

.PHONY : CMakeFiles/many_cpu.dir/requires

CMakeFiles/many_cpu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/many_cpu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/many_cpu.dir/clean

CMakeFiles/many_cpu.dir/depend:
	cd /home/liu/my_progs/lintcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liu/my_progs/lintcode /home/liu/my_progs/lintcode /home/liu/my_progs/lintcode/cmake-build-debug /home/liu/my_progs/lintcode/cmake-build-debug /home/liu/my_progs/lintcode/cmake-build-debug/CMakeFiles/many_cpu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/many_cpu.dir/depend
