#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void WriteCharToFile(char* str, string fileName)
{
    ofstream file;
    file.open(fileName, ios::out);

    file << str << endl;
}

int main()
{
    char str[] = "hello world!";
    string fileName = "test.txt";
    WriteCharToFile(str, fileName);

    return 0;
}