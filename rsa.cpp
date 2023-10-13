#include <iostream>
#include <string>
#include <string.h>
#include <unordered_map>

using namespace std;
class RSA
{
    public:
    // important parameter in RSA
    // prime num p & q
    long long p = 0;
    long long q = 0;
    // modulus n
    long long n = 0;
    // euler's toition function
    long long phi_n = 0;
    // encrypt exponent & decrypt exponent
    long long e = 0;
    long long d = 0;

    // other parameter
    // information of Plaintext
    string plaintextStr;
    int plaintextStrLenth = 0;
    // store cipher
    long long* cipher = NULL;

    private:
    void AES_Encrypt(long long e, long long n, unsigned char* plaintextChar);
    void AES_Decrypt(long long d, long long n, long long* cipher);
};

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

int main()
{
    cout << endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "请选择RSA加密(0)还是解密(1)? ";
	while(1)
	{
		cin >> choose;
		getchar();
		if((choose != 0) && (choose != 1))
			cout << "输入错误，重新输入0或1：";
		else
			break;
	}
	cout << endl;
    unsigned char plaintxt[] = "this is the scentence that will be encrypted!";

    return 0;
}