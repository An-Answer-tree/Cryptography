# -*- coding: utf-8 -*-
"""
Created on Sat Oct 21 15:58:30 2023

@author: Liu tong
"""
from functions import ecmath, operations
import random
a =  5829
b = 2079
p =  6277101735386680763835789423207666416083908700390324961279
pra = 7487
prb = 6737
G = [2436,4951]
k = random.randint(0,6277101735386680763835789423207666416083908700390324961279)
txt = input("Enter some text : ")
#Encryption
asciiList = operations.TxtToAsciiList(txt)
print('asciiList: ', asciiList)

pairLength = len(operations.ToDigits(p,65536))-1
print('pairLength: ', pairLength)

groupList = operations.grouping(asciiList,pairLength)
print('groupList: ', groupList)

bigInt = operations.bigInteger(groupList)
print('bigInt: ', bigInt)

cipherPair = operations.grouping(bigInt,2)
print('cipherPair: ', cipherPair)

C1 = ecmath.double_and_add(k,G,p,a)    # first half of ciphertxt
print('cx1: ', C1)

publicKey = ecmath.double_and_add(prb,G,p,a)
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
l2 = ecmath.double_and_add(prb,C1,p,a)
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