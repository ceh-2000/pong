# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/clareheinbaugh/Desktop/game-design/pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/clareheinbaugh/Desktop/game-design/pong/Debug

# Include any dependencies generated for this target.
include CMakeFiles/pong_core.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pong_core.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pong_core.dir/flags.make

CMakeFiles/pong_core.dir/src/Paddle.cpp.o: CMakeFiles/pong_core.dir/flags.make
CMakeFiles/pong_core.dir/src/Paddle.cpp.o: ../src/Paddle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clareheinbaugh/Desktop/game-design/pong/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pong_core.dir/src/Paddle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pong_core.dir/src/Paddle.cpp.o -c /Users/clareheinbaugh/Desktop/game-design/pong/src/Paddle.cpp

CMakeFiles/pong_core.dir/src/Paddle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pong_core.dir/src/Paddle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clareheinbaugh/Desktop/game-design/pong/src/Paddle.cpp > CMakeFiles/pong_core.dir/src/Paddle.cpp.i

CMakeFiles/pong_core.dir/src/Paddle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pong_core.dir/src/Paddle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clareheinbaugh/Desktop/game-design/pong/src/Paddle.cpp -o CMakeFiles/pong_core.dir/src/Paddle.cpp.s

CMakeFiles/pong_core.dir/src/ball.cpp.o: CMakeFiles/pong_core.dir/flags.make
CMakeFiles/pong_core.dir/src/ball.cpp.o: ../src/ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clareheinbaugh/Desktop/game-design/pong/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pong_core.dir/src/ball.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pong_core.dir/src/ball.cpp.o -c /Users/clareheinbaugh/Desktop/game-design/pong/src/ball.cpp

CMakeFiles/pong_core.dir/src/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pong_core.dir/src/ball.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clareheinbaugh/Desktop/game-design/pong/src/ball.cpp > CMakeFiles/pong_core.dir/src/ball.cpp.i

CMakeFiles/pong_core.dir/src/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pong_core.dir/src/ball.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clareheinbaugh/Desktop/game-design/pong/src/ball.cpp -o CMakeFiles/pong_core.dir/src/ball.cpp.s

CMakeFiles/pong_core.dir/src/game.cpp.o: CMakeFiles/pong_core.dir/flags.make
CMakeFiles/pong_core.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clareheinbaugh/Desktop/game-design/pong/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pong_core.dir/src/game.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pong_core.dir/src/game.cpp.o -c /Users/clareheinbaugh/Desktop/game-design/pong/src/game.cpp

CMakeFiles/pong_core.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pong_core.dir/src/game.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clareheinbaugh/Desktop/game-design/pong/src/game.cpp > CMakeFiles/pong_core.dir/src/game.cpp.i

CMakeFiles/pong_core.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pong_core.dir/src/game.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clareheinbaugh/Desktop/game-design/pong/src/game.cpp -o CMakeFiles/pong_core.dir/src/game.cpp.s

# Object files for target pong_core
pong_core_OBJECTS = \
"CMakeFiles/pong_core.dir/src/Paddle.cpp.o" \
"CMakeFiles/pong_core.dir/src/ball.cpp.o" \
"CMakeFiles/pong_core.dir/src/game.cpp.o"

# External object files for target pong_core
pong_core_EXTERNAL_OBJECTS =

libpong_core.a: CMakeFiles/pong_core.dir/src/Paddle.cpp.o
libpong_core.a: CMakeFiles/pong_core.dir/src/ball.cpp.o
libpong_core.a: CMakeFiles/pong_core.dir/src/game.cpp.o
libpong_core.a: CMakeFiles/pong_core.dir/build.make
libpong_core.a: CMakeFiles/pong_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/clareheinbaugh/Desktop/game-design/pong/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libpong_core.a"
	$(CMAKE_COMMAND) -P CMakeFiles/pong_core.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pong_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pong_core.dir/build: libpong_core.a

.PHONY : CMakeFiles/pong_core.dir/build

CMakeFiles/pong_core.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pong_core.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pong_core.dir/clean

CMakeFiles/pong_core.dir/depend:
	cd /Users/clareheinbaugh/Desktop/game-design/pong/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/clareheinbaugh/Desktop/game-design/pong /Users/clareheinbaugh/Desktop/game-design/pong /Users/clareheinbaugh/Desktop/game-design/pong/Debug /Users/clareheinbaugh/Desktop/game-design/pong/Debug /Users/clareheinbaugh/Desktop/game-design/pong/Debug/CMakeFiles/pong_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pong_core.dir/depend
