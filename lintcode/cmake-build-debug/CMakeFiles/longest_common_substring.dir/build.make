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
include CMakeFiles/longest_common_substring.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/longest_common_substring.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/longest_common_substring.dir/flags.make

CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o: CMakeFiles/longest_common_substring.dir/flags.make
CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o: ../longest_common_substring/longest_common_substring.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liu/my_progs/lintcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o -c /home/liu/my_progs/lintcode/longest_common_substring/longest_common_substring.cpp

CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liu/my_progs/lintcode/longest_common_substring/longest_common_substring.cpp > CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.i

CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liu/my_progs/lintcode/longest_common_substring/longest_common_substring.cpp -o CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.s

CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o.requires:

.PHONY : CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o.requires

CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o.provides: CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o.requires
	$(MAKE) -f CMakeFiles/longest_common_substring.dir/build.make CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o.provides.build
.PHONY : CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o.provides

CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o.provides.build: CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o


# Object files for target longest_common_substring
longest_common_substring_OBJECTS = \
"CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o"

# External object files for target longest_common_substring
longest_common_substring_EXTERNAL_OBJECTS =

longest_common_substring: CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o
longest_common_substring: CMakeFiles/longest_common_substring.dir/build.make
longest_common_substring: CMakeFiles/longest_common_substring.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liu/my_progs/lintcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable longest_common_substring"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/longest_common_substring.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/longest_common_substring.dir/build: longest_common_substring

.PHONY : CMakeFiles/longest_common_substring.dir/build

CMakeFiles/longest_common_substring.dir/requires: CMakeFiles/longest_common_substring.dir/longest_common_substring/longest_common_substring.cpp.o.requires

.PHONY : CMakeFiles/longest_common_substring.dir/requires

CMakeFiles/longest_common_substring.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/longest_common_substring.dir/cmake_clean.cmake
.PHONY : CMakeFiles/longest_common_substring.dir/clean

CMakeFiles/longest_common_substring.dir/depend:
	cd /home/liu/my_progs/lintcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liu/my_progs/lintcode /home/liu/my_progs/lintcode /home/liu/my_progs/lintcode/cmake-build-debug /home/liu/my_progs/lintcode/cmake-build-debug /home/liu/my_progs/lintcode/cmake-build-debug/CMakeFiles/longest_common_substring.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/longest_common_substring.dir/depend

