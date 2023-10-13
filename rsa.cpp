#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <random>
#include <unordered_map>
using namespace std;
// init random seed
random_device rd;
mt19937_64 gen(rd());

class RSA
{
    public:
    // important parameter in RSA
    // prime num p & q
    long long p;
    long long q;
    // modulus n
    long long n;
    // euler's toition function
    long long phi_n;
    // encrypt exponent & decrypt exponent
    long long e;
    long long d;

    // other parameter
    // information of Plaintext
    string plaintextStr;
    int plaintextStrLenth;
    // store cipher
    long long* cipher;

    RSA(long long p = 0, long long q = 0, long long n = 0, long long e = 0, long long d = 0);

    // generate random number bigger than 1 and smaller than n
    long long generateRandomNumber(long long n);

    // void RSA_Encrypt(long long e, long long n, unsigned char* plaintextChar);
    // void RSA_Decrypt(long long d, long long n, long long* cipher);
    // void KeyGeneration();

    // Miller-Rabin Primality Test
    bool IsPrime(long long n);
};
// ++++++++++++++++++++++++++++++++++++++++++Class RSA Function Define++++++++++++++++++++++++++++++++++++++++++++++++
RSA::RSA(long long p, long long q, long long n, long long e, long long d)
    :p(p), q(q), n(n), e(e), d(d)
    {}

long long RSA::generateRandomNumber(long long n)
{
    uniform_int_distribution<long long> dis(2, n - 1);
    return dis(gen);
}

bool RSA::IsPrime(long long n)
{
    if (fmod(n - 1, 2) != 0)
        return false;

    // step1: find out k and m
    long long exponent_K = 1;
    long long m = 0;
    for( ; true; exponent_K++)
    {
        long long a = fmod(n - 1, (long long) pow(2.0, exponent_K));//0
        long long temp = (n - 1) / (long long) pow(2.0, exponent_K);//3

        if (a == 0)
            m = temp;
        else
        {
            exponent_K--;
            break;
        }
    }

    // do 10 times miller rabin primality test
    int count = 0;
    while (count < 9)
    {
        // step3: select 1 < 'a' < n 
        long long a = generateRandomNumber(n - 1);
        // cout << "a = " << a << endl;

        // step3: calculate b0
        long long b0 = fmod((long long) pow(a, m), n);
        // cout << "b0 = " << b0 << endl;
        if (b0 == 1 || b0 == n - 1)
            continue;

        // step4: calculate b1, b2, b3, ...
        long long b1 = fmod((long long) pow(b0, 2), n);

        if (b1 == 1)    // must be composite number
            return false;
        else if (b1 == n - 1)    //maybe prime number
            continue;
        else    // calculate b2, b3, b4 until bn == +1 or (n-1)
        {
            long long temp = b1;
            while(true)
            {
                long long bn = fmod((long long) pow(temp, 2), n);
                if (bn == 1)    // must be composite number
                    return false;
                else if (bn == n - 1)    //maybe prime number
                    break;
                else    // calculate b2, b3, b4 until bn == +1 or (n-1)
                    temp = bn;
            }
        }
        count ++;
    }
    return true;
}







// ++++++++++++++++++++++++++++++++++++++++Class RSA Function END Define+++++++++++++++++++++++++++++++++++++++++++++++

// convert Hex Str to Char(every 2 chars are converted to 1 char)
unsigned char* HexStrToChar(string text, int n)
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
	unsigned char* res = new unsigned char[n/2];
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

// convert Char to Hex Str(every 1 char is converted to 2 chars)
string CharToHexStr(unsigned char* hex, int n)

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
int SelectFunction()
{
    int choose;
	while (1)
	{
		cin >> choose;
		getchar();
		if ((choose != 0) && (choose != 1))
			cout << "输入错误，重新输入0或1：";
		else
			break;
	}

    return choose;
}

int main()
{
    cout << endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "请选择RSA加密(0)还是解密(1)? ";
    int chooseEncOrDec = SelectFunction();
    cout << endl;

    // RSA_Encrypt
    if (chooseEncOrDec == 0)
    {
        cout << "请选择是否需要生成密钥(是'1'/否'0')？ ";
        int chooseGenerateKey = SelectFunction();
        cout << endl;
        
        if (chooseGenerateKey == 1)    // Using Key Generation Algorithm
        {
            RSA instance;
            cout << instance.IsPrime(19) << endl;
 
        }
        else                          // Already Have A Key
        {

        }
        unsigned char plaintxt[] = "this is the scentence that will be encrypted!";
    }

    // RSA_Decrypt
    if (chooseEncOrDec == 0)
    {

    }
    
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    return 0;
}