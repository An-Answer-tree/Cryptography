#include <iostream>
using namespace std;

void KeyExpansion()
{

}

void AddRoundKey(unsigned char* state, unsigned char* roundKey)
{

}

void SubBytes(unsigned char* state)
{

}

void ShiftRows(unsigned char* state)
{

}

void MixColumns()
{

}

void AES_Encrypt(unsigned char* message, unsigned char* key)
{
    //copy the first 16 bytes into 'state'
    unsigned char state[16];
    for(int i = 0; i < 16; i++)
    {
        state[i] = message[i];
    }

    int numOfRound = 16;
    
    //Initial part
    KeyExpansion();
    AddRoundKey(state, key);

    //
    for(int i = 0; i < numOfRound; i++)
    {
        SubBytes(state);
        ShiftRows(state);
        MixColumns();
        AddRoundKey(state, key);
    }

    //Final Round
    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, key);
}

int main()
{
    unsigned char message[] = "This is the message will be encrypted with AES128!";
    unsigned char key[16] = 
    {
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16
    };

    AES_Encrypt(message, key);

    return 0;
}