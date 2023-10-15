#include <iostream>
#include <fstream>
#include <string.h>
#include <gmp.h>
#include <unordered_map>
using namespace std;

#define KEY_LENGTH 2048  //Length of public key
#define BASE 16    //Input and output digits

class RSA
{
    public:
    // Large Prime Number P and Q
    mpz_t p;
    mpz_t q;

    // n, euler's totient phi_n, encrypt exponent, decrypt exponent
    mpz_t n;
    mpz_t phi_n;
    mpz_t e;
    mpz_t d;
    char* nChar;
    char* eChar;
    char* dChar;

    // plaintext and cipher
    char* hexPlaintext;
    char* plaintext;
    char* cipher;

    RSA();

    // Store Content to File
    void WriteCharToFile(char* str, string fileName);

    // Generate Large Prime P and Q
    void GenerateLargePrime();

    // Generate Key Pair (e, n) and (d, n)
    void KeyGeneration();

    // Store Plaintext to RSA::plaintext
    void AddPlainStrToHexPlaintext(string plainStr);

    // Store Cipher to RSA:: cipher
    void AddHexStrToCipher(string cipherStr);

    // Store key to RSA::e, RSA::d, RSA::n
    void AddHexStrToKey(string nStr, string eStr="", string dStr="");

    // RSA Encrypt Function
    void RSA_Encrypt();

    // RSA Decrypt Function
    void RSA_Decrypt();

    ~RSA();
};