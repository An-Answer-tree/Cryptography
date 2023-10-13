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

long long generateRandomNumber(long long n)
{
    uniform_int_distribution<long long> dis(2, n - 1);
    return dis(gen);
}

bool IsPrime(long long n)
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
    // cout << "k = " << exponent_K << endl;
    // cout << "m = " << m << endl;

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

int main()
{
    cout << IsPrime(13) << endl;
}