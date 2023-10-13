#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(long long n)
{
    if (fmod(n - 1, 2) != 0)
        return false;

    // find out k and m
    long long exponent_K = 1;
    long long m = 0;
    for( ; true; exponent_K++)
    {
        long long a = fmod(n - 1, pow(2.0, exponent_K));//0
        long long temp = (n - 1) / (long long) pow(2.0, exponent_K);//3
        if (a == 0)
        {
            m = temp;
        }
        else
        {
            exponent_K--;
            break;
        }
            
    }
    cout << "k = " << exponent_K << endl;
    cout << "m = " << m << endl;

    long long a = 2;
    long long b0 = fmod((long long) pow(a, m), n);
    cout << "b0 = " << b0 << endl;
    return false;
}

int main()
{
    long long n = 13;
    cout << IsPrime(n) << endl;
    return 0;
}