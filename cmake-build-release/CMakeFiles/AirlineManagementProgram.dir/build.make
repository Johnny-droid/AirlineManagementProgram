# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/clion/178/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/178/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/johnny/CLionProjects/AirlineManagementProgram

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/AirlineManagementProgram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AirlineManagementProgram.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AirlineManagementProgram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AirlineManagementProgram.dir/flags.make

CMakeFiles/AirlineManagementProgram.dir/main.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/main.cpp.o: ../main.cpp
CMakeFiles/AirlineManagementProgram.dir/main.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/main.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/main.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/main.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/main.cpp

CMakeFiles/AirlineManagementProgram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/main.cpp > CMakeFiles/AirlineManagementProgram.dir/main.cpp.i

CMakeFiles/AirlineManagementProgram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/main.cpp -o CMakeFiles/AirlineManagementProgram.dir/main.cpp.s

CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.o: ../src/Plane.cpp
CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/src/Plane.cpp

CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/src/Plane.cpp > CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.i

CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/src/Plane.cpp -o CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.s

CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.o: ../src/Flight.cpp
CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/src/Flight.cpp

CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/src/Flight.cpp > CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.i

CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/src/Flight.cpp -o CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.s

CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.o: ../src/Passenger.cpp
CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/src/Passenger.cpp

CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/src/Passenger.cpp > CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.i

CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/src/Passenger.cpp -o CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.s

CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.o: ../src/Airport.cpp
CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/src/Airport.cpp

CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/src/Airport.cpp > CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.i

CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/src/Airport.cpp -o CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.s

CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.o: ../Tests/tests.cpp
CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/Tests/tests.cpp

CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/Tests/tests.cpp > CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.i

CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/Tests/tests.cpp -o CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.s

CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.o: ../src/Service.cpp
CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/src/Service.cpp

CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/src/Service.cpp > CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.i

CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/src/Service.cpp -o CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.s

CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.o: ../src/Ticket.cpp
CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/src/Ticket.cpp

CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/src/Ticket.cpp > CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.i

CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/src/Ticket.cpp -o CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.s

CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.o: ../src/LocalTransport.cpp
CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/src/LocalTransport.cpp

CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/src/LocalTransport.cpp > CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.i

CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/src/LocalTransport.cpp -o CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.s

CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.o: ../src/Menu.cpp
CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/src/Menu.cpp

CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/src/Menu.cpp > CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.i

CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/src/Menu.cpp -o CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.s

CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.o: ../src/Date.cpp
CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/src/Date.cpp

CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/src/Date.cpp > CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.i

CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/src/Date.cpp -o CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.s

CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.o: CMakeFiles/AirlineManagementProgram.dir/flags.make
CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.o: ../src/Time.cpp
CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.o: CMakeFiles/AirlineManagementProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.o -MF CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.o.d -o CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.o -c /home/johnny/CLionProjects/AirlineManagementProgram/src/Time.cpp

CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnny/CLionProjects/AirlineManagementProgram/src/Time.cpp > CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.i

CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnny/CLionProjects/AirlineManagementProgram/src/Time.cpp -o CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.s

# Object files for target AirlineManagementProgram
AirlineManagementProgram_OBJECTS = \
"CMakeFiles/AirlineManagementProgram.dir/main.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.o" \
"CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.o"

# External object files for target AirlineManagementProgram
AirlineManagementProgram_EXTERNAL_OBJECTS =

AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/main.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/src/Plane.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/src/Flight.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/src/Passenger.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/src/Airport.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/Tests/tests.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/src/Service.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/src/Ticket.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/src/LocalTransport.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/src/Menu.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/src/Date.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/src/Time.cpp.o
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/build.make
AirlineManagementProgram: lib/libgtest.a
AirlineManagementProgram: lib/libgtest_main.a
AirlineManagementProgram: lib/libgtest.a
AirlineManagementProgram: CMakeFiles/AirlineManagementProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable AirlineManagementProgram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AirlineManagementProgram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AirlineManagementProgram.dir/build: AirlineManagementProgram
.PHONY : CMakeFiles/AirlineManagementProgram.dir/build

CMakeFiles/AirlineManagementProgram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AirlineManagementProgram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AirlineManagementProgram.dir/clean

CMakeFiles/AirlineManagementProgram.dir/depend:
	cd /home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johnny/CLionProjects/AirlineManagementProgram /home/johnny/CLionProjects/AirlineManagementProgram /home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release /home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release /home/johnny/CLionProjects/AirlineManagementProgram/cmake-build-release/CMakeFiles/AirlineManagementProgram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AirlineManagementProgram.dir/depend

