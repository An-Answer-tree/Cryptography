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
    
    # Key Generation
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
    
    # Encryption or Decryption
    if choice == '0':
        # choose encryption or decryption
        while True:
            choice2 = input('请选择加密(1)/解密(0): ')
            if choice2 == '1' or choice2 == '0':
                break
        
        # Encryption
        if choice2 == '1':
            while 1:
                k = random.getrandbits(256)
                if 1 < k < n:
                    break
            print('加密随机数k : ', k)
            
            plaintext = input('请输入需要加密的明文字符串: ')
            publicKeyX = input('请输入公钥的横坐标: ')
            publicKeyY = input('请输入公钥的纵坐标: ')
            print()
            publicKey = (int(publicKeyX), int(publicKeyY))
            
            asciiList = operations.TxtToAsciiList(plaintext)
            pairLength = len(operations.ToDigits(p,65536)) - 1
            groupList = operations.GroupList(asciiList,pairLength)
            bigInt = operations.bigInteger(groupList)
            cipherPair = operations.GroupList(bigInt,2)
            C1 = ecmath.double_and_add(k,G,p,a)
            print('密文C1: ', C1)
            
            temp = ecmath.double_and_add(k,publicKey,p,a)
            C2 = []                                
            for i in cipherPair:
                C2.append(ecmath.ecc_add(i[0],i[1],temp[0],temp[1],p,a))
            print('密文C2: ', C2)
            
            with open("Cipher_After_Encrypt.txt", mode='w') as file:
                print('密文C1: ', C1, '\n密文C2: ', C2, file=file)
            
        # Decryption
        if choice2 == '0':
            C1 = int(input('请输入密文C1: '))
            
            C2 = int(input('请输入密文C2: '))
            privateKey = int(input('请输入私钥: '))
            
            temp2 = ecmath.double_and_add(privateKey,C1,p,a)
            Cipher  = []
            for i in C2:
                Cipher.append(ecmath.ecc_add(i[0],i[1],temp2[0],-temp2[1],p,a))
            sml_Int = []
            for i in Cipher:
                for j in i:
                    sml_Int.append(operations.ToDigits(j,65536))
            Dicipher = ""
            for i in sml_Int:
                for j in i:
                    Dicipher = Dicipher + chr(j)
            print("decrypted msg : " + str(Dicipher))
            
            
            
    print('++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++', end='\n\n')