# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.6\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.6\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\efrai\CLionProjects\teo-proyecto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\efrai\CLionProjects\teo-proyecto\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/teo_proyecto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/teo_proyecto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/teo_proyecto.dir/flags.make

CMakeFiles/teo_proyecto.dir/main.cpp.obj: CMakeFiles/teo_proyecto.dir/flags.make
CMakeFiles/teo_proyecto.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\efrai\CLionProjects\teo-proyecto\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/teo_proyecto.dir/main.cpp.obj"
	D:\mingw\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\teo_proyecto.dir\main.cpp.obj -c C:\Users\efrai\CLionProjects\teo-proyecto\main.cpp

CMakeFiles/teo_proyecto.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/teo_proyecto.dir/main.cpp.i"
	D:\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\efrai\CLionProjects\teo-proyecto\main.cpp > CMakeFiles\teo_proyecto.dir\main.cpp.i

CMakeFiles/teo_proyecto.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/teo_proyecto.dir/main.cpp.s"
	D:\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\efrai\CLionProjects\teo-proyecto\main.cpp -o CMakeFiles\teo_proyecto.dir\main.cpp.s

# Object files for target teo_proyecto
teo_proyecto_OBJECTS = \
"CMakeFiles/teo_proyecto.dir/main.cpp.obj"

# External object files for target teo_proyecto
teo_proyecto_EXTERNAL_OBJECTS =

teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/main.cpp.obj
teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/build.make
teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/linklibs.rsp
teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/objects1.rsp
teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\efrai\CLionProjects\teo-proyecto\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable teo_proyecto.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\teo_proyecto.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/teo_proyecto.dir/build: teo_proyecto.exe

.PHONY : CMakeFiles/teo_proyecto.dir/build

CMakeFiles/teo_proyecto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\teo_proyecto.dir\cmake_clean.cmake
.PHONY : CMakeFiles/teo_proyecto.dir/clean

CMakeFiles/teo_proyecto.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\efrai\CLionProjects\teo-proyecto C:\Users\efrai\CLionProjects\teo-proyecto C:\Users\efrai\CLionProjects\teo-proyecto\cmake-build-debug C:\Users\efrai\CLionProjects\teo-proyecto\cmake-build-debug C:\Users\efrai\CLionProjects\teo-proyecto\cmake-build-debug\CMakeFiles\teo_proyecto.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/teo_proyecto.dir/depend
