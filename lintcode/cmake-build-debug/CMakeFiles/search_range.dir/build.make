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
include CMakeFiles/search_range.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/search_range.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/search_range.dir/flags.make

CMakeFiles/search_range.dir/search_range/search_range.cpp.o: CMakeFiles/search_range.dir/flags.make
CMakeFiles/search_range.dir/search_range/search_range.cpp.o: ../search_range/search_range.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liu/my_progs/lintcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/search_range.dir/search_range/search_range.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/search_range.dir/search_range/search_range.cpp.o -c /home/liu/my_progs/lintcode/search_range/search_range.cpp

CMakeFiles/search_range.dir/search_range/search_range.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/search_range.dir/search_range/search_range.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liu/my_progs/lintcode/search_range/search_range.cpp > CMakeFiles/search_range.dir/search_range/search_range.cpp.i

CMakeFiles/search_range.dir/search_range/search_range.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/search_range.dir/search_range/search_range.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liu/my_progs/lintcode/search_range/search_range.cpp -o CMakeFiles/search_range.dir/search_range/search_range.cpp.s

CMakeFiles/search_range.dir/search_range/search_range.cpp.o.requires:

.PHONY : CMakeFiles/search_range.dir/search_range/search_range.cpp.o.requires

CMakeFiles/search_range.dir/search_range/search_range.cpp.o.provides: CMakeFiles/search_range.dir/search_range/search_range.cpp.o.requires
	$(MAKE) -f CMakeFiles/search_range.dir/build.make CMakeFiles/search_range.dir/search_range/search_range.cpp.o.provides.build
.PHONY : CMakeFiles/search_range.dir/search_range/search_range.cpp.o.provides

CMakeFiles/search_range.dir/search_range/search_range.cpp.o.provides.build: CMakeFiles/search_range.dir/search_range/search_range.cpp.o


# Object files for target search_range
search_range_OBJECTS = \
"CMakeFiles/search_range.dir/search_range/search_range.cpp.o"

# External object files for target search_range
search_range_EXTERNAL_OBJECTS =

search_range: CMakeFiles/search_range.dir/search_range/search_range.cpp.o
search_range: CMakeFiles/search_range.dir/build.make
search_range: CMakeFiles/search_range.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liu/my_progs/lintcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable search_range"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/search_range.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/search_range.dir/build: search_range

.PHONY : CMakeFiles/search_range.dir/build

CMakeFiles/search_range.dir/requires: CMakeFiles/search_range.dir/search_range/search_range.cpp.o.requires

.PHONY : CMakeFiles/search_range.dir/requires

CMakeFiles/search_range.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/search_range.dir/cmake_clean.cmake
.PHONY : CMakeFiles/search_range.dir/clean

CMakeFiles/search_range.dir/depend:
	cd /home/liu/my_progs/lintcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liu/my_progs/lintcode /home/liu/my_progs/lintcode /home/liu/my_progs/lintcode/cmake-build-debug /home/liu/my_progs/lintcode/cmake-build-debug /home/liu/my_progs/lintcode/cmake-build-debug/CMakeFiles/search_range.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/search_range.dir/depend
