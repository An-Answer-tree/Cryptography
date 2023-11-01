cmake_minimum_required(VERSION 3.27.1)
project(sha512)

# set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Input path of .h file needed to be included
include_directories(${PROJECT_SOURCE_DIR}/include)

# Generate executable file with rsa.cpp and RSA_Class.cpp
add_executable(${PROJECT_NAME} src/main.cpp)