# you need to change VERSION XXX to your cmake version(like VERSION 3.27.1)
cmake_minimum_required(VERSION 3.27.1)

# set project name(this will be the name of executable file)
project(sha512)

# set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Input path of .h file needed to be included
include_directories(${PROJECT_SOURCE_DIR}/include)

# Generate executable file with main.cpp sha512.cpp
add_executable(${PROJECT_NAME} src/main.cpp src/sha512.cpp)