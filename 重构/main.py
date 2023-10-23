# -*- coding: utf-8 -*-
"""
Created on Sat Oct 21 15:58:30 2023

@author: Liu tong
"""
from functions import ecmath, operations
import random

if __name__ == "__main__":
    a = 0
    b = 7
    p = int('FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F', 16)
    G = [int('79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798', 16),int('483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8', 16)]
    n = int('FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141', 16)
    
    print()
    print('++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++')
    # Select Whether to Generate Secret Key or Encrypt/Decrypt
    while True:
        choice = input('请选择生成秘钥(1)/加密解密(0): ')
        if choice == '1' or choice == '0':
            break
    
    if choice == '1':
        # Generate Private Key
        while 1:
            privateKey = random.getrandbits(256)
            if 1 < privateKey < n:
                break
        print('privateKey is : ', privateKey)
        
        # Calculate Public Key
        publicKey = ecmath.double_and_add(privateKey, G, p, a)
        publicKeyStr = '(' + str(publicKey[0]) + ', ' + str(publicKey[1]) + ')'
        print('publicKey is : ', publicKey)
        
        # store secert key to file
        with open("./Secret_Key.txt", mode='w') as file:
            file.write("private key: ")
            file.write(str(privateKey))
            file.write('\n')
            file.write("public key: ")
            file.write(publicKeyStr)
            file.write('\n')
            
    if choice == '0':
        # choose encryption or decryption
        while True:
            choice2 = input('请选择加密(1)/解密(0): ')
            if choice2 == '1' or choice2 == '0':
                break
        
        if choice2 == '1':
            plaintext = input('请输入需要加密的明文字符串: ')
            asciiList = operations.TxtToAsciiList(plaintext)
            print('asciiList: ', asciiList)
            
            
        
        if choice2 == '2':
            pass
            
            
    print('++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++', end='\n\n')