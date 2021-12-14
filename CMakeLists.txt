cmake_minimum_required(VERSION 3.20)
project(AirlineManagementProgram)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(AirlineManagementProgram main.cpp src/Plane.cpp src/Plane.h src/Flight.cpp src/Flight.h src/Passenger.cpp src/Passenger.h src/Airport.cpp src/Airport.h Tests/tests.cpp src/Service.cpp src/Service.h src/Ticket.cpp src/Ticket.h src/LocalTransport.cpp src/LocalTransport.h src/Menu.cpp src/Menu.h)

target_link_libraries(AirlineManagementProgram gtest gtest_main)
