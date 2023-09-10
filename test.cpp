#include <iostream>
using namespace std;

void TestFunction(unsigned char* test)
{
    test[0] = 4;
}

int main()
{
    unsigned char test[4] = {1,2,3,4};
    TestFunction(test);
    cout << test[0];
    return 0;
}