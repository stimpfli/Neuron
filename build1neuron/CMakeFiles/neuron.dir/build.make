# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/INTRANET/stimpfli/myfiles/cpp/Neuron

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/INTRANET/stimpfli/myfiles/cpp/Neuron/build1neuron

# Include any dependencies generated for this target.
include CMakeFiles/neuron.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/neuron.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/neuron.dir/flags.make

CMakeFiles/neuron.dir/Neuron.cpp.o: CMakeFiles/neuron.dir/flags.make
CMakeFiles/neuron.dir/Neuron.cpp.o: ../Neuron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/stimpfli/myfiles/cpp/Neuron/build1neuron/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/neuron.dir/Neuron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/neuron.dir/Neuron.cpp.o -c /home/INTRANET/stimpfli/myfiles/cpp/Neuron/Neuron.cpp

CMakeFiles/neuron.dir/Neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neuron.dir/Neuron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/stimpfli/myfiles/cpp/Neuron/Neuron.cpp > CMakeFiles/neuron.dir/Neuron.cpp.i

CMakeFiles/neuron.dir/Neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neuron.dir/Neuron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/stimpfli/myfiles/cpp/Neuron/Neuron.cpp -o CMakeFiles/neuron.dir/Neuron.cpp.s

CMakeFiles/neuron.dir/Neuron.cpp.o.requires:
.PHONY : CMakeFiles/neuron.dir/Neuron.cpp.o.requires

CMakeFiles/neuron.dir/Neuron.cpp.o.provides: CMakeFiles/neuron.dir/Neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/neuron.dir/build.make CMakeFiles/neuron.dir/Neuron.cpp.o.provides.build
.PHONY : CMakeFiles/neuron.dir/Neuron.cpp.o.provides

CMakeFiles/neuron.dir/Neuron.cpp.o.provides.build: CMakeFiles/neuron.dir/Neuron.cpp.o

CMakeFiles/neuron.dir/Neuronmain.cpp.o: CMakeFiles/neuron.dir/flags.make
CMakeFiles/neuron.dir/Neuronmain.cpp.o: ../Neuronmain.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/stimpfli/myfiles/cpp/Neuron/build1neuron/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/neuron.dir/Neuronmain.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/neuron.dir/Neuronmain.cpp.o -c /home/INTRANET/stimpfli/myfiles/cpp/Neuron/Neuronmain.cpp

CMakeFiles/neuron.dir/Neuronmain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neuron.dir/Neuronmain.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/stimpfli/myfiles/cpp/Neuron/Neuronmain.cpp > CMakeFiles/neuron.dir/Neuronmain.cpp.i

CMakeFiles/neuron.dir/Neuronmain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neuron.dir/Neuronmain.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/stimpfli/myfiles/cpp/Neuron/Neuronmain.cpp -o CMakeFiles/neuron.dir/Neuronmain.cpp.s

CMakeFiles/neuron.dir/Neuronmain.cpp.o.requires:
.PHONY : CMakeFiles/neuron.dir/Neuronmain.cpp.o.requires

CMakeFiles/neuron.dir/Neuronmain.cpp.o.provides: CMakeFiles/neuron.dir/Neuronmain.cpp.o.requires
	$(MAKE) -f CMakeFiles/neuron.dir/build.make CMakeFiles/neuron.dir/Neuronmain.cpp.o.provides.build
.PHONY : CMakeFiles/neuron.dir/Neuronmain.cpp.o.provides

CMakeFiles/neuron.dir/Neuronmain.cpp.o.provides.build: CMakeFiles/neuron.dir/Neuronmain.cpp.o

CMakeFiles/neuron.dir/Network.cpp.o: CMakeFiles/neuron.dir/flags.make
CMakeFiles/neuron.dir/Network.cpp.o: ../Network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/stimpfli/myfiles/cpp/Neuron/build1neuron/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/neuron.dir/Network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/neuron.dir/Network.cpp.o -c /home/INTRANET/stimpfli/myfiles/cpp/Neuron/Network.cpp

CMakeFiles/neuron.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neuron.dir/Network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/stimpfli/myfiles/cpp/Neuron/Network.cpp > CMakeFiles/neuron.dir/Network.cpp.i

CMakeFiles/neuron.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neuron.dir/Network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/stimpfli/myfiles/cpp/Neuron/Network.cpp -o CMakeFiles/neuron.dir/Network.cpp.s

CMakeFiles/neuron.dir/Network.cpp.o.requires:
.PHONY : CMakeFiles/neuron.dir/Network.cpp.o.requires

CMakeFiles/neuron.dir/Network.cpp.o.provides: CMakeFiles/neuron.dir/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/neuron.dir/build.make CMakeFiles/neuron.dir/Network.cpp.o.provides.build
.PHONY : CMakeFiles/neuron.dir/Network.cpp.o.provides

CMakeFiles/neuron.dir/Network.cpp.o.provides.build: CMakeFiles/neuron.dir/Network.cpp.o

# Object files for target neuron
neuron_OBJECTS = \
"CMakeFiles/neuron.dir/Neuron.cpp.o" \
"CMakeFiles/neuron.dir/Neuronmain.cpp.o" \
"CMakeFiles/neuron.dir/Network.cpp.o"

# External object files for target neuron
neuron_EXTERNAL_OBJECTS =

neuron: CMakeFiles/neuron.dir/Neuron.cpp.o
neuron: CMakeFiles/neuron.dir/Neuronmain.cpp.o
neuron: CMakeFiles/neuron.dir/Network.cpp.o
neuron: CMakeFiles/neuron.dir/build.make
neuron: CMakeFiles/neuron.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable neuron"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/neuron.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/neuron.dir/build: neuron
.PHONY : CMakeFiles/neuron.dir/build

CMakeFiles/neuron.dir/requires: CMakeFiles/neuron.dir/Neuron.cpp.o.requires
CMakeFiles/neuron.dir/requires: CMakeFiles/neuron.dir/Neuronmain.cpp.o.requires
CMakeFiles/neuron.dir/requires: CMakeFiles/neuron.dir/Network.cpp.o.requires
.PHONY : CMakeFiles/neuron.dir/requires

CMakeFiles/neuron.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/neuron.dir/cmake_clean.cmake
.PHONY : CMakeFiles/neuron.dir/clean

CMakeFiles/neuron.dir/depend:
	cd /home/INTRANET/stimpfli/myfiles/cpp/Neuron/build1neuron && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/INTRANET/stimpfli/myfiles/cpp/Neuron /home/INTRANET/stimpfli/myfiles/cpp/Neuron /home/INTRANET/stimpfli/myfiles/cpp/Neuron/build1neuron /home/INTRANET/stimpfli/myfiles/cpp/Neuron/build1neuron /home/INTRANET/stimpfli/myfiles/cpp/Neuron/build1neuron/CMakeFiles/neuron.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/neuron.dir/depend

