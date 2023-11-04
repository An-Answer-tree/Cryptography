#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

// �ṹ�����ڶ�����ƿ�
typedef struct
{
    unsigned long long count[2];
    unsigned long long h[8];
    unsigned char buffer[128];
} SHA512_Control_Block;

// ��ʼ����������ʼ��SHA_CB�ĸ���ֵ
void SHA512Init(SHA512_Control_Block *context);

// �����ݼ���
void SHA512Update(SHA512_Control_Block *context, unsigned char *input, unsigned long long inputlen);

// ����������ٵ��ã��������β��
void SHA512Final(SHA512_Control_Block *context, unsigned char digest[32]);

// ���ܴ�������Hash���ܵĺ��Ĺ���
void SHA512Transform(unsigned long long state[8], unsigned char block[128]);

// ���뺯���������ͱ���תΪ�ַ�
void SHA512Encode(unsigned char *output, unsigned long long *input, unsigned long long len);

// ���뺯��:���ַ����鱣��ı���תΪ����
void SHA512Decode(unsigned long long *output, unsigned char *input, unsigned long long len);
