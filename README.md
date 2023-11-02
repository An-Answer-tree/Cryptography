# SHA-512 Implementation in C++

## reset CMakeList.txt
```
# you need to change VERSION XXX to your cmake version(like VERSION 3.27.1)
cmake_minimum_required(VERSION XXX)

# set project name(this will be the name of executable file)
project(sha512)

# set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Input path of .h file needed to be included
include_directories(${PROJECT_SOURCE_DIR}/include)

# Generate executable file with main.cpp
add_executable(${PROJECT_NAME} src/main.cpp)

```

## how to use

- cd /ProjectDir/
- mkdir build
- cd build
- cmake ..
- make
- ./sha512

## instruction

When running the program, you can input 'text'. Then it will output the hash of the 'text'.