#include "RSA_Class.hpp"

RSA::RSA()
{
    mpz_init(n);
    mpz_init(phi_n);
    mpz_init(e);
    mpz_init(d);
}

void RSA::WriteCharToFile(char* str, string fileName)
{
    ofstream file;
    file.open(fileName, ios::out);

    file << str << endl;
}

void RSA::GenerateLargePrime()
{
    // init random number generator
    gmp_randstate_t grt;
    gmp_randinit_default(grt);
    gmp_randseed_ui(grt, time(NULL));
	
    // init tempP and tempQ
    mpz_t tempP, tempQ;
    mpz_init(tempP);
    mpz_init(tempQ);
 
    // Random Generation of Two Large Integers
    mpz_urandomb(tempP, grt, KEY_LENGTH / 2);  // tempP now is not a prime
    mpz_urandomb(tempQ, grt, KEY_LENGTH / 2);  // tempQ now is not a prime

    // init p and q
    mpz_init(p);
    mpz_init(q);
 
    //Using the Prime Generation Function of GMP to calculate the prime after the second parameter
    mpz_nextprime(p, tempP);  // RSA::p now is a prime
    mpz_nextprime(q, tempQ);  // RSA::q now is a prime

    // free the memory
    mpz_clear(tempP);
    mpz_clear(tempQ);

    // p and q have 1024bits and we need (1024 / 4) char to store hex text
    char* pChar = new char[(KEY_LENGTH / 2 / 4) + 1] {0};
    char* qChar = new char[(KEY_LENGTH / 2 / 4) + 1] {0};

    // store p, q to file
    mpz_get_str(pChar, BASE, p);
    WriteCharToFile(pChar,"p.txt");
    mpz_get_str(qChar, BASE, q);
    WriteCharToFile(qChar,"q.txt");
 
    //  free the memory
    delete[] pChar;
    delete[] qChar;
}

void RSA::KeyGeneration()
{
    // calculate n
    mpz_mul(n, p, q);

    // calculate phi_n
    mpz_sub_ui(p, p, 1);  // p = p - 1
    mpz_sub_ui(q, q, 1);  // q = q - 1
    mpz_mul(phi_n, p, q); // phi_n = (p - 1) * (q - 1)

    // select e = 65537
    mpz_set_ui(e, 65537);

    // calculate d
    mpz_invert(d, e, phi_n);

    // save (e, n) and (d, n) to file
    // new char[]
    char* eChar = new char[20];
    char* dChar = new char[(KEY_LENGTH / 4) + 5];
    char* nChar = new char[(KEY_LENGTH / 4) + 5];
    // covert mpz_t to HEX char*
    mpz_get_str(eChar, BASE, e);
    mpz_get_str(dChar, BASE, d);
    mpz_get_str(nChar, BASE, n);
    // to file
    WriteCharToFile(eChar, "key_e.txt");
    WriteCharToFile(dChar, "key_d.txt");
    WriteCharToFile(nChar, "key_n.txt");

    // free the memery
    delete[] eChar;
    delete[] dChar;
    delete[] nChar;
}

char* RSA::HexStrToChar(string text, int n)
{
	unordered_map<char, int> mp;
    for(int i=0; i<10; i++)
    {
        mp[i + '0'] = i;
    }
    for(int i=0; i<6; i++)
    {
        mp[i + 'a'] = i + 10;
    }
	char* res = new char[n/2 + 1] {0};
	for(int i=0; i<n/2; i++)
	{
		char c1 = text.at(i*2);
		char c2 = text.at(i*2+1);
		int b1 = mp[c1];
		int b2 = mp[c2];
		res[i] = 16*b1 + b2;
	}
	return res;
}

string RSA::CharToHexStr(char* hex, int n)
{
	unordered_map<char, int> mp;
    for(int i=0; i<10; i++)
    {
        mp[i] = i + '0';
    }
    for(int i=0; i<6; i++)
    {
        mp[i + 10] = i + 'a';
    }
	string res;
	for(int i=0; i<n; i++)
	{
		int x = hex[i];
        int b1 = mp[x/16];
        int b2 = mp[x%16];
        res += string(1, b1) + string(1, b2);
	}
	return res;
}


void RSA::AddPlainStrToHexPlaintext(string plainStr)
{
    unordered_map<int, char> mp;
    for (int i = 0; i < 10; i++)
    {
        mp[i] = '0' + i;
    }
    for (int i = 0; i < 6; i++)
    {
        mp[i + 10] = 'a' + i;
    }

    int plainStrLength = plainStr.length();
    plaintext = new char[2 * plainStrLength + 1] {0};
    for (int i = 0; i < plainStrLength; i++)
    {
        int charNum = (int) plainStr[i];
        char first = mp[charNum / BASE];
        char second = mp[charNum % BASE];
        plaintext[2 * i] = first;
        plaintext[2 * i + 1] = second;
    }
}

void RSA::AddHexStrToCipher(string cipherStr)
{
    int cipherStrLength = cipherStr.length();
    cipher = new char[cipherStrLength / 2 + 1] {0};
    char* temp = HexStrToChar(cipherStr, cipherStrLength);
    memcpy(cipher, temp, cipherStrLength / 2);
    delete[] temp;
}

void RSA::RSA_Encrypt()
{
    mpz_t mpzMessage, mpzCipher;
    mpz_init(mpzMessage);
    mpz_init(mpzCipher);

    mpz_set_str(mpzMessage, plaintext, BASE);
    mpz_powm(mpzCipher, mpzMessage, e, n);

    cipher = new char[(KEY_LENGTH / 4) + 5];
    mpz_get_str(cipher, BASE, mpzCipher);
    WriteCharToFile(cipher, "cipher_after_encrypt.txt");

    mpz_clear(mpzMessage);
    mpz_clear(mpzCipher);
}

void RSA::RSA_Decrypt()
{
    
}

RSA::~RSA()
{
    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(n);
    mpz_clear(phi_n);
    mpz_clear(e);
    mpz_clear(d);
}