# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\LociStar\CLionProjects\ChessEngineCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ChessEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ChessEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ChessEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ChessEngine.dir/flags.make

CMakeFiles/ChessEngine.dir/main.cpp.obj: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/main.cpp.obj: ../main.cpp
CMakeFiles/ChessEngine.dir/main.cpp.obj: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ChessEngine.dir/main.cpp.obj"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/main.cpp.obj -MF CMakeFiles\ChessEngine.dir\main.cpp.obj.d -o CMakeFiles\ChessEngine.dir\main.cpp.obj -c C:\Users\LociStar\CLionProjects\ChessEngineCPP\main.cpp

CMakeFiles/ChessEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/main.cpp.i"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LociStar\CLionProjects\ChessEngineCPP\main.cpp > CMakeFiles\ChessEngine.dir\main.cpp.i

CMakeFiles/ChessEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/main.cpp.s"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LociStar\CLionProjects\ChessEngineCPP\main.cpp -o CMakeFiles\ChessEngine.dir\main.cpp.s

CMakeFiles/ChessEngine.dir/engine.cpp.obj: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/engine.cpp.obj: ../engine.cpp
CMakeFiles/ChessEngine.dir/engine.cpp.obj: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ChessEngine.dir/engine.cpp.obj"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/engine.cpp.obj -MF CMakeFiles\ChessEngine.dir\engine.cpp.obj.d -o CMakeFiles\ChessEngine.dir\engine.cpp.obj -c C:\Users\LociStar\CLionProjects\ChessEngineCPP\engine.cpp

CMakeFiles/ChessEngine.dir/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/engine.cpp.i"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LociStar\CLionProjects\ChessEngineCPP\engine.cpp > CMakeFiles\ChessEngine.dir\engine.cpp.i

CMakeFiles/ChessEngine.dir/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/engine.cpp.s"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LociStar\CLionProjects\ChessEngineCPP\engine.cpp -o CMakeFiles\ChessEngine.dir\engine.cpp.s

CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.obj: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.obj: ../src/chess_engine.cpp
CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.obj: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.obj"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.obj -MF CMakeFiles\ChessEngine.dir\src\chess_engine.cpp.obj.d -o CMakeFiles\ChessEngine.dir\src\chess_engine.cpp.obj -c C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\chess_engine.cpp

CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.i"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\chess_engine.cpp > CMakeFiles\ChessEngine.dir\src\chess_engine.cpp.i

CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.s"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\chess_engine.cpp -o CMakeFiles\ChessEngine.dir\src\chess_engine.cpp.s

CMakeFiles/ChessEngine.dir/src/position.cpp.obj: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/position.cpp.obj: ../src/position.cpp
CMakeFiles/ChessEngine.dir/src/position.cpp.obj: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ChessEngine.dir/src/position.cpp.obj"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/src/position.cpp.obj -MF CMakeFiles\ChessEngine.dir\src\position.cpp.obj.d -o CMakeFiles\ChessEngine.dir\src\position.cpp.obj -c C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\position.cpp

CMakeFiles/ChessEngine.dir/src/position.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/position.cpp.i"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\position.cpp > CMakeFiles\ChessEngine.dir\src\position.cpp.i

CMakeFiles/ChessEngine.dir/src/position.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/position.cpp.s"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\position.cpp -o CMakeFiles\ChessEngine.dir\src\position.cpp.s

CMakeFiles/ChessEngine.dir/src/tables.cpp.obj: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/tables.cpp.obj: ../src/tables.cpp
CMakeFiles/ChessEngine.dir/src/tables.cpp.obj: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ChessEngine.dir/src/tables.cpp.obj"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/src/tables.cpp.obj -MF CMakeFiles\ChessEngine.dir\src\tables.cpp.obj.d -o CMakeFiles\ChessEngine.dir\src\tables.cpp.obj -c C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\tables.cpp

CMakeFiles/ChessEngine.dir/src/tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/tables.cpp.i"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\tables.cpp > CMakeFiles\ChessEngine.dir\src\tables.cpp.i

CMakeFiles/ChessEngine.dir/src/tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/tables.cpp.s"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\tables.cpp -o CMakeFiles\ChessEngine.dir\src\tables.cpp.s

CMakeFiles/ChessEngine.dir/src/types.cpp.obj: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/types.cpp.obj: ../src/types.cpp
CMakeFiles/ChessEngine.dir/src/types.cpp.obj: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ChessEngine.dir/src/types.cpp.obj"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/src/types.cpp.obj -MF CMakeFiles\ChessEngine.dir\src\types.cpp.obj.d -o CMakeFiles\ChessEngine.dir\src\types.cpp.obj -c C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\types.cpp

CMakeFiles/ChessEngine.dir/src/types.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/types.cpp.i"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\types.cpp > CMakeFiles\ChessEngine.dir\src\types.cpp.i

CMakeFiles/ChessEngine.dir/src/types.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/types.cpp.s"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\types.cpp -o CMakeFiles\ChessEngine.dir\src\types.cpp.s

CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.obj: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.obj: ../src/LinkedListDoubly.cpp
CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.obj: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.obj"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.obj -MF CMakeFiles\ChessEngine.dir\src\LinkedListDoubly.cpp.obj.d -o CMakeFiles\ChessEngine.dir\src\LinkedListDoubly.cpp.obj -c C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\LinkedListDoubly.cpp

CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.i"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\LinkedListDoubly.cpp > CMakeFiles\ChessEngine.dir\src\LinkedListDoubly.cpp.i

CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.s"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LociStar\CLionProjects\ChessEngineCPP\src\LinkedListDoubly.cpp -o CMakeFiles\ChessEngine.dir\src\LinkedListDoubly.cpp.s

CMakeFiles/ChessEngine.dir/positionTables.cpp.obj: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/positionTables.cpp.obj: ../positionTables.cpp
CMakeFiles/ChessEngine.dir/positionTables.cpp.obj: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ChessEngine.dir/positionTables.cpp.obj"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/positionTables.cpp.obj -MF CMakeFiles\ChessEngine.dir\positionTables.cpp.obj.d -o CMakeFiles\ChessEngine.dir\positionTables.cpp.obj -c C:\Users\LociStar\CLionProjects\ChessEngineCPP\positionTables.cpp

CMakeFiles/ChessEngine.dir/positionTables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/positionTables.cpp.i"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LociStar\CLionProjects\ChessEngineCPP\positionTables.cpp > CMakeFiles\ChessEngine.dir\positionTables.cpp.i

CMakeFiles/ChessEngine.dir/positionTables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/positionTables.cpp.s"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LociStar\CLionProjects\ChessEngineCPP\positionTables.cpp -o CMakeFiles\ChessEngine.dir\positionTables.cpp.s

CMakeFiles/ChessEngine.dir/UCI.cpp.obj: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/UCI.cpp.obj: ../UCI.cpp
CMakeFiles/ChessEngine.dir/UCI.cpp.obj: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ChessEngine.dir/UCI.cpp.obj"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/UCI.cpp.obj -MF CMakeFiles\ChessEngine.dir\UCI.cpp.obj.d -o CMakeFiles\ChessEngine.dir\UCI.cpp.obj -c C:\Users\LociStar\CLionProjects\ChessEngineCPP\UCI.cpp

CMakeFiles/ChessEngine.dir/UCI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/UCI.cpp.i"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LociStar\CLionProjects\ChessEngineCPP\UCI.cpp > CMakeFiles\ChessEngine.dir\UCI.cpp.i

CMakeFiles/ChessEngine.dir/UCI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/UCI.cpp.s"
	C:\Users\LociStar\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3345.126\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LociStar\CLionProjects\ChessEngineCPP\UCI.cpp -o CMakeFiles\ChessEngine.dir\UCI.cpp.s

# Object files for target ChessEngine
ChessEngine_OBJECTS = \
"CMakeFiles/ChessEngine.dir/main.cpp.obj" \
"CMakeFiles/ChessEngine.dir/engine.cpp.obj" \
"CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.obj" \
"CMakeFiles/ChessEngine.dir/src/position.cpp.obj" \
"CMakeFiles/ChessEngine.dir/src/tables.cpp.obj" \
"CMakeFiles/ChessEngine.dir/src/types.cpp.obj" \
"CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.obj" \
"CMakeFiles/ChessEngine.dir/positionTables.cpp.obj" \
"CMakeFiles/ChessEngine.dir/UCI.cpp.obj"

# External object files for target ChessEngine
ChessEngine_EXTERNAL_OBJECTS =

ChessEngine.exe: CMakeFiles/ChessEngine.dir/main.cpp.obj
ChessEngine.exe: CMakeFiles/ChessEngine.dir/engine.cpp.obj
ChessEngine.exe: CMakeFiles/ChessEngine.dir/src/chess_engine.cpp.obj
ChessEngine.exe: CMakeFiles/ChessEngine.dir/src/position.cpp.obj
ChessEngine.exe: CMakeFiles/ChessEngine.dir/src/tables.cpp.obj
ChessEngine.exe: CMakeFiles/ChessEngine.dir/src/types.cpp.obj
ChessEngine.exe: CMakeFiles/ChessEngine.dir/src/LinkedListDoubly.cpp.obj
ChessEngine.exe: CMakeFiles/ChessEngine.dir/positionTables.cpp.obj
ChessEngine.exe: CMakeFiles/ChessEngine.dir/UCI.cpp.obj
ChessEngine.exe: CMakeFiles/ChessEngine.dir/build.make
ChessEngine.exe: CMakeFiles/ChessEngine.dir/linklibs.rsp
ChessEngine.exe: CMakeFiles/ChessEngine.dir/objects1.rsp
ChessEngine.exe: CMakeFiles/ChessEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ChessEngine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ChessEngine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ChessEngine.dir/build: ChessEngine.exe
.PHONY : CMakeFiles/ChessEngine.dir/build

CMakeFiles/ChessEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ChessEngine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ChessEngine.dir/clean

CMakeFiles/ChessEngine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\LociStar\CLionProjects\ChessEngineCPP C:\Users\LociStar\CLionProjects\ChessEngineCPP C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug C:\Users\LociStar\CLionProjects\ChessEngineCPP\cmake-build-debug\CMakeFiles\ChessEngine.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ChessEngine.dir/depend

