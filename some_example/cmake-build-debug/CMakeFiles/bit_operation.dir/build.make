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
include CMakeFiles/bit_operation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bit_operation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bit_operation.dir/flags.make

CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o: CMakeFiles/bit_operation.dir/flags.make
CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o: ../bit_operation/bit_operation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liu/my_progs/example/some_example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o -c /home/liu/my_progs/example/some_example/bit_operation/bit_operation.cpp

CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liu/my_progs/example/some_example/bit_operation/bit_operation.cpp > CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.i

CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liu/my_progs/example/some_example/bit_operation/bit_operation.cpp -o CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.s

CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o.requires:

.PHONY : CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o.requires

CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o.provides: CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o.requires
	$(MAKE) -f CMakeFiles/bit_operation.dir/build.make CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o.provides.build
.PHONY : CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o.provides

CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o.provides.build: CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o


# Object files for target bit_operation
bit_operation_OBJECTS = \
"CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o"

# External object files for target bit_operation
bit_operation_EXTERNAL_OBJECTS =

bit_operation: CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o
bit_operation: CMakeFiles/bit_operation.dir/build.make
bit_operation: CMakeFiles/bit_operation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liu/my_progs/example/some_example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bit_operation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bit_operation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bit_operation.dir/build: bit_operation

.PHONY : CMakeFiles/bit_operation.dir/build

CMakeFiles/bit_operation.dir/requires: CMakeFiles/bit_operation.dir/bit_operation/bit_operation.cpp.o.requires

.PHONY : CMakeFiles/bit_operation.dir/requires

CMakeFiles/bit_operation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bit_operation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bit_operation.dir/clean

CMakeFiles/bit_operation.dir/depend:
	cd /home/liu/my_progs/example/some_example/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liu/my_progs/example/some_example /home/liu/my_progs/example/some_example /home/liu/my_progs/example/some_example/cmake-build-debug /home/liu/my_progs/example/some_example/cmake-build-debug /home/liu/my_progs/example/some_example/cmake-build-debug/CMakeFiles/bit_operation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bit_operation.dir/depend
