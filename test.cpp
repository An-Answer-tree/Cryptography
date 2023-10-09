#include <iostream>
#include <string>
#include <string.h>

using namespace std;

unsigned char* Padding(unsigned char* plaintxt)
{
    int originalLenth = strlen((const char*)plaintxt);
    
    if(originalLenth % 16 != 0)
    {
        int lenthAfterPadding = originalLenth + (16 - (originalLenth % 16));
        unsigned char* temp = new unsigned char[lenthAfterPadding];

        for(int i = 0; i < lenthAfterPadding; i++)
        {
            if(i < originalLenth)
                temp[i] = plaintxt[i];
            else
                temp[i] = '0';
        }

        return temp;
    }
    else
    {
        return plaintxt;
    }

}

int main()
{
    // store content after encrypt/decrypt
    string total_enc = "";
	string total_dec = "";

    // Variable
    unsigned char* plaintxt_char;
    unsigned char* key_char;
    string plaintxt_str;
    string key_str;

    // process plaintxt
    cout << "请输入明文原文(如\"Hello Word!\"):";
    cout << endl;
    cin >> plaintxt_str;
    plaintxt_char = (unsigned char*)plaintxt_str.c_str();
    // padding
    unsigned char* paddingPlaintxt = Padding(plaintxt_char);


    // process key
    cout << "请输入加密密钥(十六进制字符串):";
    cin >> key_str;
    key_char = StringToHex(key_str, 32);
    // KeyExpandsion
    unsigned char *expanded_key = ExpandKey(key);

    // Encrypt
    int lenthAfterPadding = strlen((const char*)paddingPlaintxt);
    int timesToEnc = lenthAfterPadding / 16;
    for(int i = 0; i < timesToEnc; i++)
    {
        total_enc += HexToString(AES_Encrypt(paddingPlaintxt, expanded_key));
    }




    return 0;
}