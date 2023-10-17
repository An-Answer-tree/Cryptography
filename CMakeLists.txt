# Version of CMake
cmake_minimum_required(VERSION 3.27.1)

# Input name of project ${PROJECT_NAME} = XXX
project(rsa)

# set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Input path of .h file needed to be included
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/local/include)

# Input path of link(链接库)
link_directories(/usr/local/lib)

# Generate executable file with rsa.cpp and RSA_Class.cpp
add_executable(${PROJECT_NAME} src/rsa.cpp src/RSA_Class.cpp)

# Link the program
target_link_libraries(${PROJECT_NAME} PRIVATE gmp)