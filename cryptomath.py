'''
2023/6/14
by TongLiu
'''
import math

def Euclid(a, b):
    '''
    calculate gdc(a, b)
    '''
    if b == 0:
        return a
    return Euclid(b, a % b)