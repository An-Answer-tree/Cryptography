#include <iostream>
#include <string.h>
#include <cstring>
#include "../include/sha512.hpp"
using namespace std;

// Ring Shift Right(64 bits)
#define RSR64(value, bits) (((value) >> (bits)) | ((value) << (64 - (bits))))

// Ch, Maj operation
// S:Ring Shift Right    R:同2**128除余右移
// Sigma0:Sigma0 function
// Sigma1:Sigma2 function
// Gamma0:Gamma0 function
// Gamma1:Gamma1 function

#define Ch(x, y, z)     (z ^ (x & (y ^ z)))
#define Maj(x, y, z)    (((x | y) & z) | (x & y))
#define S(x, n)         RSR64( x, n )
#define R(x, n)         (((x)&0xFFFFFFFFFFFFFFFFULL)>>((unsigned long long)n))
#define Sigma0(x)       (S(x, 28) ^ S(x, 34) ^ S(x, 39))
#define Sigma1(x)       (S(x, 14) ^ S(x, 18) ^ S(x, 41))
#define Gamma0(x)       (S(x, 1) ^ S(x, 8) ^ R(x, 7))
#define Gamma1(x)       (S(x, 19) ^ S(x, 61) ^ R(x, 6))

#define Sha512Round(a, b, c, d, e, f, g, h, i)       \
     t0 = h + Sigma1(e) + Ch(e, f, g) + K[i] + W[i];   \
     t1 = Sigma0(a) + Maj(a, b, c);                    \
     d += t0;                                          \
     h  = t0 + t1;

void SHA512Init(SHA512_Control_Block *context)
{
    context->count[0] = 0;
    context->count[1] = 0;
    context->h[0] = 0x6a09e667f3bcc908ULL;
    context->h[1] = 0xbb67ae8584caa73bULL;
    context->h[2] = 0x3c6ef372fe94f82bULL;
    context->h[3] = 0xa54ff53a5f1d36f1ULL;
    context->h[4] = 0x510e527fade682d1ULL;
    context->h[5] = 0x9b05688c2b3e6c1fULL;
    context->h[6] = 0x1f83d9abfb41bd6bULL;
    context->h[7] = 0x5be0cd19137e2179ULL;
}

void SHA512Update(SHA512_Control_Block *context, unsigned char *input, unsigned long long inputlen)
{
    unsigned long long index = 0, partlen = 0, i = 0; // i记录input的当前位置（初始为0）
    index = (context->count[1] >> 3) & 0x7F;  //index:总字长除127(11111111)取余后的余数
    partlen = 128 - index;  //partlen:同128相差的长度
    context->count[1] += inputlen << 3;  //更新count

    // 统计字符的bit长度，如果小于说明类型溢出了(64bit)无法装下了
    // 由于最后留下128bit填充字符长度，因而必须引入count[1]保存
    // 64bit+64bit=128bit
    if (context->count[1] < (inputlen << 3))
        context->count[0]++;
    //右移动61位后就是count[0]应该记录的值。（左移3位，溢出的就是右移动61位的）
    context->count[0] += inputlen >> 61;

    if (inputlen >= partlen)
    {
        //将缺的partlen个字节数据加入缓冲区
        memcpy(&context->buffer[index], input, partlen);
        SHA512Transform(context->h, context->buffer);

        // 如果输入的字，还可以进行（还有整128字的）就继续进行一次加密循环

        for (i = partlen; i + 128 <= inputlen; i += 128)
            SHA512Transform(context->h, &input[i]);
        // 将当前位置设为0
        index = 0;
    }
    else
    {
        i = 0;
    }
    // 重新设置buffer区（处理过的字被覆盖成新字）
    memcpy(&context->buffer[index], &input[i], inputlen - i);
}

void SHA512Final(SHA512_Control_Block *context, unsigned char digest[64]) {
    unsigned int index = 0, padlen = 0;
    unsigned char bits[16]; // 记录字长信息
    index = (context->count[1] >> 3) & 0x7F; // 字长除127(11111111)取余长度
    padlen = (index < 112) ? (112 - index) : (240 - index); // 补齐的字长
    SHA512Encode(bits, context->count, 16);
    SHA512Update(context, PADDING, padlen);
    SHA512Update(context, bits, 16);
    SHA512Encode(digest, context->h, 64);
}

void SHA512Encode(unsigned char *output, unsigned long long *input, unsigned long long len)
{
    unsigned long long i = 0, j = 0;
    while (j < len)
    {
        output[j+7] = input[i] & 0xFF;
        output[j + 6] = (input[i] >> 8) & 0xFF; //0xFF:11111111
        output[j + 5] = (input[i] >> 16) & 0xFF;
        output[j + 4] = (input[i] >> 24) & 0xFF;
        output[j + 3] = (input[i] >> 32) & 0xFF;
        output[j + 2] = (input[i] >> 40) & 0xFF;
        output[j + 1] = (input[i] >> 48) & 0xFF;
        output[j] = (input[i] >> 56) & 0xFF;
        i++;
        j += 8;
    }
}


void SHA512Decode(unsigned long long *output, unsigned char *input, unsigned long long len)
{
    unsigned long long i = 0, j = 0;
    while (j < len)
    {
        output[i] = ((unsigned long long)input[j+7]) |
                    ((unsigned long long)input[j + 6] << 8) |
                    ((unsigned long long)input[j + 5] << 16) |
                    ((unsigned long long)input[j + 4] << 24) |
                    ((unsigned long long)input[j + 3] << 32) |
                    ((unsigned long long)input[j + 2] << 40) |
                    ((unsigned long long)input[j + 1] << 48) |
                    ((unsigned long long)input[j] << 56);
        i++;
        j += 8;
    }
}

void SHA512Transform(unsigned long long state[8], unsigned char block[128])
{
    unsigned long long S[8];
    unsigned long long W[80];
    unsigned long long t0;
    unsigned long long t1;
    int i = 0;
    printf("\n填充后(1024bits):\n0x");
    for(int index=0;index<128;index++){
        printf("%02x", block[index]);
    }
    printf("\n");
    // 把state的值复制给S
    for ( i = 0; i < 8; i++ )
    {
        S[i] = state[i];
    }

    // 将字符数组保存的编码转为unsigned long long
    SHA512Decode(W, block, 128);

    for ( i = 16; i < 80; i++ )
    {
        W[i] = Gamma1(W[i - 2]) + W[i - 7] + Gamma0(W[i - 15]) + W[i - 16];
    }

    for ( i = 0; i < 80; i += 8 )
    {
        Sha512Round(S[0], S[1], S[2], S[3], S[4], S[5], S[6], S[7], i + 0);
        Sha512Round(S[7], S[0], S[1], S[2], S[3], S[4], S[5], S[6], i + 1);
        Sha512Round(S[6], S[7], S[0], S[1], S[2], S[3], S[4], S[5], i + 2);
        Sha512Round(S[5], S[6], S[7], S[0], S[1], S[2], S[3], S[4], i + 3);
        Sha512Round(S[4], S[5], S[6], S[7], S[0], S[1], S[2], S[3], i + 4);
        Sha512Round(S[3], S[4], S[5], S[6], S[7], S[0], S[1], S[2], i + 5);
        Sha512Round(S[2], S[3], S[4], S[5], S[6], S[7], S[0], S[1], i + 6);
        Sha512Round(S[1], S[2], S[3], S[4], S[5], S[6], S[7], S[0], i + 7);
    }
    cout << endl;

    for ( i = 0; i < 8; i++ )
    {
        state[i] = state[i] + S[i];
    }
}

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

    cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    return 0;
}