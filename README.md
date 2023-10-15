# RSA Encryption/Decryption Algorithm

&emsp;&emsp;This project implements the RSA encryption/decryption algorithm using the GMP library for arbitrary precision arithmetic. The algorithm provides a secure method for encrypting and decrypting messages, ensuring the confidentiality of communication.

## My_Environment

- Operating System: Unix-like(MacOS)  
- build tools: cmake  
- External Dependency: GMP (GNU Multiple Precision Arithmetic Library)  

## GMP Installation

&emsp;&emsp;Go to https://gmplib.org and download gmp  
&emsp;&emsp;Following the official documention, using the methods below to install:  

1. GMP has an autoconf/automake/libtool based configuration system. On a Unix-like system a basic build can be done with  
```
./configure
make
```
2. Some self-tests can be run with  
```
make check
```
3. And you can install (under /usr/local by default) with  
```
make install
```

## CMake Build
&emsp;&emsp;It depends on `CMake` to compile cpp file to executable file when having a complex directory structure.  
&emsp;&emsp;Directory structure of look like:  
├── include
│   ├── RSA_Class.hpp
├── src
│   ├── RSA_Class.cpp
│   ├── rsa.cpp
├── CMakeLists.txt  
  
&emsp;&emsp;Before build executable file, you need to modify `CMakeLists.txt`:  
```
# input your cmake version
cmake_minimum_required(VERSION XXX)

# set project name
project(rsa)

# set C++ standard
set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

# input your gmp-library's 'include_path' and 'lib_path'(On Unix-like OS, the default path of gmp is /usr/local)
include_directories(/XXX/XXX/include)
link_directories(/XXX/XXX/lib)

add_executable(${PROJECT_NAME} src/rsa.cpp src/RSA_Class.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gmp)
```
&emsp;&emsp;Run code in terminal to build the cpp file:
```
cd /your/path/Cryptography
mkdir build
cd build
cmake ..
make
```
&emsp;&emsp;Then you can find executable file named `rsa` in folder `build`. You can run `./rsa` in terminal:
```
./rsa
```



