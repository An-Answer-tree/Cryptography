#include "../include/sha512.hpp"

int main()
{
    cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "请输入需要求hash的字符串: ";
    string inputStr;
    getline(cin, inputStr);
    int inputStrLen = inputStr.length();
    unsigned char* input = new unsigned char[inputStrLen + 1] {0};
    input = (unsigned char*)inputStr.c_str();

    cout <<"输入字符串的十六进制: 0x";
    for(int i = 0; i < inputStrLen; i++)
    {
        printf("%02x", input[i]);
    }
    cout << "\n";

    unsigned char sha512Code[64];

    SHA512_Control_Block sha512;

    SHA512Init(&sha512);
    SHA512Update(&sha512, input, inputStrLen);
    SHA512Final(&sha512, sha512Code);

    //SHA512结果输出
    printf("消息:%s\n512位哈希值:", input);
    for (int i = 0; i < 64; i++)
    {
        printf("%02x", sha512Code[i]);
    }

    cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "按下回车键以退出...\n";
    getchar();
    return 0;
}