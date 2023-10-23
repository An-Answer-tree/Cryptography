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

def GroupList(listBeforeGrouped,numOfElements): 
    """It will partition the ascii values into groups

    Args:
        list (list): list before grouping. exp:[97, 98, 99, 100]
        pairn (int): the number of elements every group has. exp:2

    Returns:
        groupedList: like [[97, 98], [99, 10]]
    """    
    groupedList = []
    count = 0
    partList = []
    for i in range(len(listBeforeGrouped)):
        partList.append(listBeforeGrouped[i])
        count = count+1
        if count==numOfElements :
            groupedList.append(partList)
            count,partList = 0,[]
        elif i==len(listBeforeGrouped)-1:
            groupedList.append(partList)
    return groupedList

def ConvertOtherBaseToDec(digitsList, base):
    """Convert other base digits stored by list to Dec int

    Args:
        digits (1D-list): 
        b (_type_): _description_

    Returns:
        _type_: _description_
    """    
    n = 0
    for d in digitsList:
        n = base * n + d
    return n

def bigInteger(list): 
    """_summary_

    Args:
        list (_type_): _description_

    Returns:
        _type_: _description_
    """    #converts each group of ascii value into big Integer.
    bigI = []
    for i in list:
        bigI.append(ConvertOtherBaseToDec(i,65536))
    if len(bigI)%2!=0:
        bigI.append(32)
    return bigI
