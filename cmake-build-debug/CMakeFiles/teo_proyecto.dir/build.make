# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\teo_proyecto.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\teo_proyecto.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\teo_proyecto.dir\flags.make

CMakeFiles\teo_proyecto.dir\main.cpp.obj: CMakeFiles\teo_proyecto.dir\flags.make
CMakeFiles\teo_proyecto.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/teo_proyecto.dir/main.cpp.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\teo_proyecto.dir\main.cpp.obj /FdCMakeFiles\teo_proyecto.dir\ /FS -c "C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto\main.cpp"
<<

CMakeFiles\teo_proyecto.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/teo_proyecto.dir/main.cpp.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\teo_proyecto.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto\main.cpp"
<<

CMakeFiles\teo_proyecto.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/teo_proyecto.dir/main.cpp.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\teo_proyecto.dir\main.cpp.s /c "C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto\main.cpp"
<<

# Object files for target teo_proyecto
teo_proyecto_OBJECTS = \
"CMakeFiles\teo_proyecto.dir\main.cpp.obj"

# External object files for target teo_proyecto
teo_proyecto_EXTERNAL_OBJECTS =

teo_proyecto.exe: CMakeFiles\teo_proyecto.dir\main.cpp.obj
teo_proyecto.exe: CMakeFiles\teo_proyecto.dir\build.make
teo_proyecto.exe: CMakeFiles\teo_proyecto.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable teo_proyecto.exe"
	"C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\teo_proyecto.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\teo_proyecto.dir\objects1.rsp @<<
 /out:teo_proyecto.exe /implib:teo_proyecto.lib /pdb:"C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto\cmake-build-debug\teo_proyecto.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\teo_proyecto.dir\build: teo_proyecto.exe

.PHONY : CMakeFiles\teo_proyecto.dir\build

CMakeFiles\teo_proyecto.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\teo_proyecto.dir\cmake_clean.cmake
.PHONY : CMakeFiles\teo_proyecto.dir\clean

CMakeFiles\teo_proyecto.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto" "C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto" "C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto\cmake-build-debug" "C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto\cmake-build-debug" "C:\Users\Wese\Downloads\Teoria_proyecto-main (3)\Teoria_proyecto-main\Teoria_proyecto\cmake-build-debug\CMakeFiles\teo_proyecto.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\teo_proyecto.dir\depend

