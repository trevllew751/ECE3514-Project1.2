# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Trevl\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Trevl\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\student-tests.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\student-tests.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\student-tests.dir\flags.make

CMakeFiles\student-tests.dir\student_catch.cpp.obj: CMakeFiles\student-tests.dir\flags.make
CMakeFiles\student-tests.dir\student_catch.cpp.obj: ..\student_catch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/student-tests.dir/student_catch.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\student-tests.dir\student_catch.cpp.obj /FdCMakeFiles\student-tests.dir\ /FS -c "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\student_catch.cpp"
<<

CMakeFiles\student-tests.dir\student_catch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/student-tests.dir/student_catch.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\student-tests.dir\student_catch.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\student_catch.cpp"
<<

CMakeFiles\student-tests.dir\student_catch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/student-tests.dir/student_catch.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\student-tests.dir\student_catch.cpp.s /c "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\student_catch.cpp"
<<

CMakeFiles\student-tests.dir\Matrix.cpp.obj: CMakeFiles\student-tests.dir\flags.make
CMakeFiles\student-tests.dir\Matrix.cpp.obj: ..\Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/student-tests.dir/Matrix.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\student-tests.dir\Matrix.cpp.obj /FdCMakeFiles\student-tests.dir\ /FS -c "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\Matrix.cpp"
<<

CMakeFiles\student-tests.dir\Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/student-tests.dir/Matrix.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\student-tests.dir\Matrix.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\Matrix.cpp"
<<

CMakeFiles\student-tests.dir\Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/student-tests.dir/Matrix.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\student-tests.dir\Matrix.cpp.s /c "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\Matrix.cpp"
<<

CMakeFiles\student-tests.dir\Hill.cpp.obj: CMakeFiles\student-tests.dir\flags.make
CMakeFiles\student-tests.dir\Hill.cpp.obj: ..\Hill.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/student-tests.dir/Hill.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\student-tests.dir\Hill.cpp.obj /FdCMakeFiles\student-tests.dir\ /FS -c "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\Hill.cpp"
<<

CMakeFiles\student-tests.dir\Hill.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/student-tests.dir/Hill.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\student-tests.dir\Hill.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\Hill.cpp"
<<

CMakeFiles\student-tests.dir\Hill.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/student-tests.dir/Hill.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\student-tests.dir\Hill.cpp.s /c "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\Hill.cpp"
<<

CMakeFiles\student-tests.dir\student_tests.cpp.obj: CMakeFiles\student-tests.dir\flags.make
CMakeFiles\student-tests.dir\student_tests.cpp.obj: ..\student_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/student-tests.dir/student_tests.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\student-tests.dir\student_tests.cpp.obj /FdCMakeFiles\student-tests.dir\ /FS -c "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\student_tests.cpp"
<<

CMakeFiles\student-tests.dir\student_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/student-tests.dir/student_tests.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\student-tests.dir\student_tests.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\student_tests.cpp"
<<

CMakeFiles\student-tests.dir\student_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/student-tests.dir/student_tests.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\student-tests.dir\student_tests.cpp.s /c "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\student_tests.cpp"
<<

# Object files for target student-tests
student__tests_OBJECTS = \
"CMakeFiles\student-tests.dir\student_catch.cpp.obj" \
"CMakeFiles\student-tests.dir\Matrix.cpp.obj" \
"CMakeFiles\student-tests.dir\Hill.cpp.obj" \
"CMakeFiles\student-tests.dir\student_tests.cpp.obj"

# External object files for target student-tests
student__tests_EXTERNAL_OBJECTS =

student-tests.exe: CMakeFiles\student-tests.dir\student_catch.cpp.obj
student-tests.exe: CMakeFiles\student-tests.dir\Matrix.cpp.obj
student-tests.exe: CMakeFiles\student-tests.dir\Hill.cpp.obj
student-tests.exe: CMakeFiles\student-tests.dir\student_tests.cpp.obj
student-tests.exe: CMakeFiles\student-tests.dir\build.make
student-tests.exe: CMakeFiles\student-tests.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable student-tests.exe"
	C:\Users\Trevl\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\student-tests.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\student-tests.dir\objects1.rsp @<<
 /out:student-tests.exe /implib:student-tests.lib /pdb:"C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\cmake-build-debug\student-tests.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\student-tests.dir\build: student-tests.exe

.PHONY : CMakeFiles\student-tests.dir\build

CMakeFiles\student-tests.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\student-tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles\student-tests.dir\clean

CMakeFiles\student-tests.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2" "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2" "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\cmake-build-debug" "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\cmake-build-debug" "C:\Users\Trevl\Desktop\Projects\School\ECE 3514  - Data Structures and Algorithms\Project 1.2\ECE3514-Project1.2\cmake-build-debug\CMakeFiles\student-tests.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\student-tests.dir\depend

