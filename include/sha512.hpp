#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

// 结构体用于定义控制块
typedef struct
{
    unsigned long long count[2];
    unsigned long long h[8];
    unsigned char buffer[128];
} SHA512_Control_Block;

// 初始化函数，初始化SHA_CB的各个值
void SHA512Init(SHA512_Control_Block *context);

// 将数据加入
void SHA512Update(SHA512_Control_Block *context, unsigned char *input, unsigned long long inputlen);

// 处理完最后再调用，这个处理尾数
void SHA512Final(SHA512_Control_Block *context, unsigned char digest[32]);

// 加密处理函数：Hash加密的核心工厂
void SHA512Transform(unsigned long long state[8], unsigned char block[128]);

// 编码函数：将整型编码转为字符
void SHA512Encode(unsigned char *output, unsigned long long *input, unsigned long long len);

// 解码函数:将字符数组保存的编码转为整型
void SHA512Decode(unsigned long long *output, unsigned char *input, unsigned long long len);
