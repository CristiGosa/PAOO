# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cristi/PAOO/PAOO/tema1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cristi/PAOO/PAOO/tema1/build

# Include any dependencies generated for this target.
include CMakeFiles/circus.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/circus.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/circus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/circus.dir/flags.make

CMakeFiles/circus.dir/src/main.cpp.o: CMakeFiles/circus.dir/flags.make
CMakeFiles/circus.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/circus.dir/src/main.cpp.o: CMakeFiles/circus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cristi/PAOO/PAOO/tema1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/circus.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/circus.dir/src/main.cpp.o -MF CMakeFiles/circus.dir/src/main.cpp.o.d -o CMakeFiles/circus.dir/src/main.cpp.o -c /home/cristi/PAOO/PAOO/tema1/src/main.cpp

CMakeFiles/circus.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/circus.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cristi/PAOO/PAOO/tema1/src/main.cpp > CMakeFiles/circus.dir/src/main.cpp.i

CMakeFiles/circus.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/circus.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cristi/PAOO/PAOO/tema1/src/main.cpp -o CMakeFiles/circus.dir/src/main.cpp.s

CMakeFiles/circus.dir/src/circus.cpp.o: CMakeFiles/circus.dir/flags.make
CMakeFiles/circus.dir/src/circus.cpp.o: ../src/circus.cpp
CMakeFiles/circus.dir/src/circus.cpp.o: CMakeFiles/circus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cristi/PAOO/PAOO/tema1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/circus.dir/src/circus.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/circus.dir/src/circus.cpp.o -MF CMakeFiles/circus.dir/src/circus.cpp.o.d -o CMakeFiles/circus.dir/src/circus.cpp.o -c /home/cristi/PAOO/PAOO/tema1/src/circus.cpp

CMakeFiles/circus.dir/src/circus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/circus.dir/src/circus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cristi/PAOO/PAOO/tema1/src/circus.cpp > CMakeFiles/circus.dir/src/circus.cpp.i

CMakeFiles/circus.dir/src/circus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/circus.dir/src/circus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cristi/PAOO/PAOO/tema1/src/circus.cpp -o CMakeFiles/circus.dir/src/circus.cpp.s

# Object files for target circus
circus_OBJECTS = \
"CMakeFiles/circus.dir/src/main.cpp.o" \
"CMakeFiles/circus.dir/src/circus.cpp.o"

# External object files for target circus
circus_EXTERNAL_OBJECTS =

circus: CMakeFiles/circus.dir/src/main.cpp.o
circus: CMakeFiles/circus.dir/src/circus.cpp.o
circus: CMakeFiles/circus.dir/build.make
circus: CMakeFiles/circus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cristi/PAOO/PAOO/tema1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable circus"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/circus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/circus.dir/build: circus
.PHONY : CMakeFiles/circus.dir/build

CMakeFiles/circus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/circus.dir/cmake_clean.cmake
.PHONY : CMakeFiles/circus.dir/clean

CMakeFiles/circus.dir/depend:
	cd /home/cristi/PAOO/PAOO/tema1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cristi/PAOO/PAOO/tema1 /home/cristi/PAOO/PAOO/tema1 /home/cristi/PAOO/PAOO/tema1/build /home/cristi/PAOO/PAOO/tema1/build /home/cristi/PAOO/PAOO/tema1/build/CMakeFiles/circus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/circus.dir/depend

