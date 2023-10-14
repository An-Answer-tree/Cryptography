#include <iostream>
#include <fstream>
#include <string.h>
#include <gmp.h>
using namespace std;

#define KEY_LENGTH 2048  //Length of public key
#define BASE 16    //Input and output digits

class RSA
{
    public:
    // Large Prime Number P and Q
    mpz_t p;
    mpz_t q;

    // Store content to file
    void WriteCharToFile(char* str, string fileName);

    // Generate Prime P and Q
    mpz_t* GenerateLargePrime();
    
};