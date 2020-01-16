#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 25 12:22:33 2018

@author: misskeisha
"""
def is_prime(n):
    if n >1:
        for i in range(2,n):
            if n%i == 0:
                return False
        return True 
    else:
        return False 
n = int(input("please enter a positive integer"))
sum = 0
while n != 0:
    if is_prime(n) == True:
        sum += n
    n = int(input("please enter a positive integer"))
print(sum)    
    
        