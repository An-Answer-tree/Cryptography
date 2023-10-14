#include "crypto_tools.hpp"

void RSA::WriteCharToFile(char* str, string fileName)
{
    ofstream file;
    file.open(fileName, ios::out);

    file << str << endl;
}

//Generate two large prime numbers
mpz_t* RSA::GenerateLargePrime()
{
    // init random number generator
    gmp_randstate_t grt;
    gmp_randinit_default(grt);
    gmp_randseed_ui(grt, time(NULL));
	
    // init p and q
    mpz_init(p);
    mpz_init(q);
 
    // Random Generation of Two Large Integers
    mpz_urandomb(p, grt, KEY_LENGTH / 2);
    mpz_urandomb(q, grt, KEY_LENGTH / 2);
 
    mpz_t* result = new mpz_t[2];
    mpz_init(result[0]);
    mpz_init(result[1]);
 
  mpz_nextprime(result[0], rsa_p);  //Using the Prime Generation Function of GMP
  mpz_nextprime(result[1], rsa_q);
  char * buf_p = new char[KEY_LENGTH + 10];
  char * buf_q = new char[KEY_LENGTH + 10];

  mpz_get_str(buf_p, BASE, rsa_p);
  writefile(buf_p,"p.txt");
  mpz_get_str(buf_q, BASE, rsa_q);
  writefile(buf_q,"q.txt");
 
  mpz_clear(rsa_p);
  mpz_clear(rsa_q);
 
  return result;	
}