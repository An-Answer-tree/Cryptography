# -*- coding: utf-8 -*-
"""
Created on Sat Oct 21 15:58:30 2023

@author: Liu tong
"""

def TxtToAsciiList(string):
    """converts text to ascii

    Args:
        string (string): the plaintext that is needed to be encrypted

    Returns:
        asciiList (list): from string each char was store in list element as an ascii number
    """    
    asciiList = []
    for i in string:
        asciiList.append(ord(i))
    return asciiList

def ToDigits(n, base):
    """Convert a positive number n to its digit representation in base

    Args:
        n (int): a positive number
        base (int): base

    Returns:
        digits (list): the 
    """    
    digits = []
    while n > 0:
        digits.insert(0, n % base)
        n  = n // base
    return digits

def grouping(list,pairn): 
    """It will partition the ascii values into groups

    Args:
        list (_type_): _description_
        pairn (_type_): _description_

    Returns:
        _type_: _description_
    """    
    groupsList,n,l = [],0,[]
    for i in range(len(list)):
        l.append(list[i])
        n = n+1
        if n==pairn :
            groupsList.append(l)
            n,l = 0,[]
        elif i==len(list)-1:
            groupsList.append(l)
    return groupsList
def fromDigits(digits, b):
    """Compute the number given by digits in base b."""
    n = 0
    for d in digits:
        n = b * n + d
    return n
def bigInteger(list): #converts each group of ascii value into big Integer.
    bigI = []
    for i in list:
        bigI.append(fromDigits(i,65536))
    if len(bigI)%2!=0:
        bigI.append(32)
    return bigI
