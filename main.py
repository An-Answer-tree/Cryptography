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
    privateKey = random.getrandbits(256)
    G = [int('79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798', 16),int('483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8', 16)]
    k = random.randint(0,6277101735386680763835789423207666416083908700390324961279)
    txt = input("Enter some text : ")
    #Encryption
    asciiList = operations.TxtToAsciiList(txt)
    print('asciiList: ', asciiList)

    pairLength = len(operations.ToDigits(p,65536))-1
    print('pairLength: ', pairLength)

    groupList = operations.GroupList(asciiList,pairLength)
    print('groupList: ', groupList)

    bigInt = operations.bigInteger(groupList)
    print('bigInt: ', bigInt)

    cipherPair = operations.GroupList(bigInt,2)
    print('cipherPair: ', cipherPair)

    C1 = ecmath.double_and_add(k,G,p,a)    # first half of ciphertxt
    print('C1: ', C1)

    publicKey = ecmath.double_and_add(privateKey,G,p,a)
    print('publicKey: ', publicKey)

    lamxp = ecmath.double_and_add(k,publicKey,p,a)
    C2 = []                                # second half of cipher text
    for i in cipherPair:
        C2.append(ecmath.ecc_add(i[0],i[1],lamxp[0],lamxp[1],p,a))
    print("-------------------------------------------------------------------")
    print("-------------------------------------------------------------------")
    print("Encrypted msg : " + str([C1,C2]))
    print("-------------------------------------------------------------------")
    print("-------------------------------------------------------------------")

    #Decryption
    l2 = ecmath.double_and_add(privateKey,C1,p,a)
    Cipher  = [] #pm
    for i in C2:
        Cipher.append(ecmath.ecc_add(i[0],i[1],l2[0],-l2[1],p,a))
    sml_Int = []
    for i in Cipher:
        for j in i:
            sml_Int.append(operations.ToDigits(j,65536))
    Dicipher = ""
    for i in sml_Int:
        for j in i:
            Dicipher = Dicipher + chr(j)
    print("decrypted msg : " + str(Dicipher))
    print("-------------------------------------------------------------------")
    print("-------------------------------------------------------------------")