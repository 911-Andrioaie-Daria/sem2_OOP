# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\daria\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-1\203.7148.70\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\daria\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-1\203.7148.70\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/a1_911_Andrioaie_Daria_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a1_911_Andrioaie_Daria_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a1_911_Andrioaie_Daria_1.dir/flags.make

CMakeFiles/a1_911_Andrioaie_Daria_1.dir/problem_4.c.obj: CMakeFiles/a1_911_Andrioaie_Daria_1.dir/flags.make
CMakeFiles/a1_911_Andrioaie_Daria_1.dir/problem_4.c.obj: ../problem\ 4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/a1_911_Andrioaie_Daria_1.dir/problem_4.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\a1_911_Andrioaie_Daria_1.dir\problem_4.c.obj   -c "C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1\problem 4.c"

CMakeFiles/a1_911_Andrioaie_Daria_1.dir/problem_4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/a1_911_Andrioaie_Daria_1.dir/problem_4.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1\problem 4.c" > CMakeFiles\a1_911_Andrioaie_Daria_1.dir\problem_4.c.i

CMakeFiles/a1_911_Andrioaie_Daria_1.dir/problem_4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/a1_911_Andrioaie_Daria_1.dir/problem_4.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1\problem 4.c" -o CMakeFiles\a1_911_Andrioaie_Daria_1.dir\problem_4.c.s

# Object files for target a1_911_Andrioaie_Daria_1
a1_911_Andrioaie_Daria_1_OBJECTS = \
"CMakeFiles/a1_911_Andrioaie_Daria_1.dir/problem_4.c.obj"

# External object files for target a1_911_Andrioaie_Daria_1
a1_911_Andrioaie_Daria_1_EXTERNAL_OBJECTS =

a1_911_Andrioaie_Daria_1.exe: CMakeFiles/a1_911_Andrioaie_Daria_1.dir/problem_4.c.obj
a1_911_Andrioaie_Daria_1.exe: CMakeFiles/a1_911_Andrioaie_Daria_1.dir/build.make
a1_911_Andrioaie_Daria_1.exe: CMakeFiles/a1_911_Andrioaie_Daria_1.dir/linklibs.rsp
a1_911_Andrioaie_Daria_1.exe: CMakeFiles/a1_911_Andrioaie_Daria_1.dir/objects1.rsp
a1_911_Andrioaie_Daria_1.exe: CMakeFiles/a1_911_Andrioaie_Daria_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable a1_911_Andrioaie_Daria_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\a1_911_Andrioaie_Daria_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a1_911_Andrioaie_Daria_1.dir/build: a1_911_Andrioaie_Daria_1.exe

.PHONY : CMakeFiles/a1_911_Andrioaie_Daria_1.dir/build

CMakeFiles/a1_911_Andrioaie_Daria_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\a1_911_Andrioaie_Daria_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/a1_911_Andrioaie_Daria_1.dir/clean

CMakeFiles/a1_911_Andrioaie_Daria_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1" "C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1" "C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1\cmake-build-debug" "C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1\cmake-build-debug" "C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a1-911-Andrioaie-Daria-1\cmake-build-debug\CMakeFiles\a1_911_Andrioaie_Daria_1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/a1_911_Andrioaie_Daria_1.dir/depend

