#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  9 16:09:42 2018

@author: misskeisha
"""
n = int(input())

smallest = (3,4,5) 
def pyhold(htuple):
    if ((htuple[0]**2) + (htuple[1]**2) == (htuple[2]**2)): 
        return True 
    return False 


def multiple(htuple):
        if htuple[0] % smallest[0] == 0 and htuple[1] % smallest[1] == 0 and htuple[2] % smallest[2] == 0: 
            return True     
        return False 
def generator(n):
    ltuples= [ ]
    for a in range(1,n):
        for b in range (1,n):
            for c in range(1,n): 
                if a + b + c <= n and  pyhold((a,b,c)) and multiple((a,b,c)) == False:
                    ltuples.append((a,b,c))
    return ltuples
    
    

print(generator(n))

