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
CMAKE_SOURCE_DIR = /home/liu/my_progs/example/some_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liu/my_progs/example/some_example/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/std_function.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/std_function.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/std_function.dir/flags.make

CMakeFiles/std_function.dir/std_function/std_function.cpp.o: CMakeFiles/std_function.dir/flags.make
CMakeFiles/std_function.dir/std_function/std_function.cpp.o: ../std_function/std_function.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liu/my_progs/example/some_example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/std_function.dir/std_function/std_function.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/std_function.dir/std_function/std_function.cpp.o -c /home/liu/my_progs/example/some_example/std_function/std_function.cpp

CMakeFiles/std_function.dir/std_function/std_function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/std_function.dir/std_function/std_function.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liu/my_progs/example/some_example/std_function/std_function.cpp > CMakeFiles/std_function.dir/std_function/std_function.cpp.i

CMakeFiles/std_function.dir/std_function/std_function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/std_function.dir/std_function/std_function.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liu/my_progs/example/some_example/std_function/std_function.cpp -o CMakeFiles/std_function.dir/std_function/std_function.cpp.s

CMakeFiles/std_function.dir/std_function/std_function.cpp.o.requires:

.PHONY : CMakeFiles/std_function.dir/std_function/std_function.cpp.o.requires

CMakeFiles/std_function.dir/std_function/std_function.cpp.o.provides: CMakeFiles/std_function.dir/std_function/std_function.cpp.o.requires
	$(MAKE) -f CMakeFiles/std_function.dir/build.make CMakeFiles/std_function.dir/std_function/std_function.cpp.o.provides.build
.PHONY : CMakeFiles/std_function.dir/std_function/std_function.cpp.o.provides

CMakeFiles/std_function.dir/std_function/std_function.cpp.o.provides.build: CMakeFiles/std_function.dir/std_function/std_function.cpp.o


# Object files for target std_function
std_function_OBJECTS = \
"CMakeFiles/std_function.dir/std_function/std_function.cpp.o"

# External object files for target std_function
std_function_EXTERNAL_OBJECTS =

std_function: CMakeFiles/std_function.dir/std_function/std_function.cpp.o
std_function: CMakeFiles/std_function.dir/build.make
std_function: CMakeFiles/std_function.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liu/my_progs/example/some_example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable std_function"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/std_function.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/std_function.dir/build: std_function

.PHONY : CMakeFiles/std_function.dir/build

CMakeFiles/std_function.dir/requires: CMakeFiles/std_function.dir/std_function/std_function.cpp.o.requires

.PHONY : CMakeFiles/std_function.dir/requires

CMakeFiles/std_function.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/std_function.dir/cmake_clean.cmake
.PHONY : CMakeFiles/std_function.dir/clean

CMakeFiles/std_function.dir/depend:
	cd /home/liu/my_progs/example/some_example/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liu/my_progs/example/some_example /home/liu/my_progs/example/some_example /home/liu/my_progs/example/some_example/cmake-build-debug /home/liu/my_progs/example/some_example/cmake-build-debug /home/liu/my_progs/example/some_example/cmake-build-debug/CMakeFiles/std_function.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/std_function.dir/depend

