#include "RSA_Class.hpp"

int main()
{
    // init an instance
    RSA instance;

    // generate p, q
    instance.GenerateLargePrime();

    // generate e, d, n
    instance.KeyGeneration();


    return 0; 
}

