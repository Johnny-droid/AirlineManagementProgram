cmake_minimum_required(VERSION 3.20)
project(AirlineManagementProgram)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(AirlineManagementProgram main.cpp src/Plane.cpp src/Plane.h src/Flight.cpp src/Flight.h src/Passenger.cpp src/Passenger.h src/Ticket.cpp src/Ticket.h)

target_link_libraries(AirlineManagementProgram gtest gtest_main)
