# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rdesantiago/Developer/C++/MazeSolver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rdesantiago/Developer/C++/MazeSolver/build

# Include any dependencies generated for this target.
include CMakeFiles/MazeSolver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MazeSolver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MazeSolver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MazeSolver.dir/flags.make

CMakeFiles/MazeSolver.dir/main.cpp.o: CMakeFiles/MazeSolver.dir/flags.make
CMakeFiles/MazeSolver.dir/main.cpp.o: /Users/rdesantiago/Developer/C++/MazeSolver/main.cpp
CMakeFiles/MazeSolver.dir/main.cpp.o: CMakeFiles/MazeSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rdesantiago/Developer/C++/MazeSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MazeSolver.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MazeSolver.dir/main.cpp.o -MF CMakeFiles/MazeSolver.dir/main.cpp.o.d -o CMakeFiles/MazeSolver.dir/main.cpp.o -c /Users/rdesantiago/Developer/C++/MazeSolver/main.cpp

CMakeFiles/MazeSolver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MazeSolver.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rdesantiago/Developer/C++/MazeSolver/main.cpp > CMakeFiles/MazeSolver.dir/main.cpp.i

CMakeFiles/MazeSolver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MazeSolver.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rdesantiago/Developer/C++/MazeSolver/main.cpp -o CMakeFiles/MazeSolver.dir/main.cpp.s

CMakeFiles/MazeSolver.dir/Maze.cpp.o: CMakeFiles/MazeSolver.dir/flags.make
CMakeFiles/MazeSolver.dir/Maze.cpp.o: /Users/rdesantiago/Developer/C++/MazeSolver/Maze.cpp
CMakeFiles/MazeSolver.dir/Maze.cpp.o: CMakeFiles/MazeSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/rdesantiago/Developer/C++/MazeSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MazeSolver.dir/Maze.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MazeSolver.dir/Maze.cpp.o -MF CMakeFiles/MazeSolver.dir/Maze.cpp.o.d -o CMakeFiles/MazeSolver.dir/Maze.cpp.o -c /Users/rdesantiago/Developer/C++/MazeSolver/Maze.cpp

CMakeFiles/MazeSolver.dir/Maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MazeSolver.dir/Maze.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rdesantiago/Developer/C++/MazeSolver/Maze.cpp > CMakeFiles/MazeSolver.dir/Maze.cpp.i

CMakeFiles/MazeSolver.dir/Maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MazeSolver.dir/Maze.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rdesantiago/Developer/C++/MazeSolver/Maze.cpp -o CMakeFiles/MazeSolver.dir/Maze.cpp.s

# Object files for target MazeSolver
MazeSolver_OBJECTS = \
"CMakeFiles/MazeSolver.dir/main.cpp.o" \
"CMakeFiles/MazeSolver.dir/Maze.cpp.o"

# External object files for target MazeSolver
MazeSolver_EXTERNAL_OBJECTS =

MazeSolver: CMakeFiles/MazeSolver.dir/main.cpp.o
MazeSolver: CMakeFiles/MazeSolver.dir/Maze.cpp.o
MazeSolver: CMakeFiles/MazeSolver.dir/build.make
MazeSolver: /opt/homebrew/lib/libsfml-graphics.2.6.1.dylib
MazeSolver: /opt/homebrew/lib/libsfml-audio.2.6.1.dylib
MazeSolver: /opt/homebrew/lib/libsfml-network.2.6.1.dylib
MazeSolver: /opt/homebrew/lib/libsfml-window.2.6.1.dylib
MazeSolver: /opt/homebrew/lib/libsfml-system.2.6.1.dylib
MazeSolver: CMakeFiles/MazeSolver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/rdesantiago/Developer/C++/MazeSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MazeSolver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MazeSolver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MazeSolver.dir/build: MazeSolver
.PHONY : CMakeFiles/MazeSolver.dir/build

CMakeFiles/MazeSolver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MazeSolver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MazeSolver.dir/clean

CMakeFiles/MazeSolver.dir/depend:
	cd /Users/rdesantiago/Developer/C++/MazeSolver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rdesantiago/Developer/C++/MazeSolver /Users/rdesantiago/Developer/C++/MazeSolver /Users/rdesantiago/Developer/C++/MazeSolver/build /Users/rdesantiago/Developer/C++/MazeSolver/build /Users/rdesantiago/Developer/C++/MazeSolver/build/CMakeFiles/MazeSolver.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MazeSolver.dir/depend

