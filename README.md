# RSA Encryption/Decryption Algorithm

This project implements the RSA encryption/decryption algorithm using the GMP library for arbitrary precision arithmetic. The algorithm provides a secure method for encrypting and decrypting messages, ensuring the confidentiality of communication.

## My_Environment

- Operating System: Unix like(MacOS)  
- Compiler: clang++  
- External Dependency: GMP (GNU Multiple Precision Arithmetic Library)  

## GMP Installation

Go to https://gmplib.org and download gmp  
Following the official documention, using the methods below to install:  

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

## Configure Compile Environment In VScode
See the blog below:  
https://blog.csdn.net/weixin_44338712/article/details/108614229