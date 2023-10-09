#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    unsigned char* plaintxt_char;
    string plaintxt_str;
    cout << "请输入明文原文";
    
    cin >> plaintxt_str;

    plaintxt_char = (unsigned char*)plaintxt_str.c_str();

    cout << plaintxt_char;

    return 0;
}