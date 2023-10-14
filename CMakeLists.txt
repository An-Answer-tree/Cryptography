cmake_minimum_required(VERSION 3.27.1)
project(rsa)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(${PROJECT_NAME} src/rsa.cpp src/RSA_Class.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gmp)