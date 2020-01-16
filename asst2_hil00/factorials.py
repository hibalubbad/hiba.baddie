#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 18 15:49:04 2018

@author: misskeisha
"""
def factorial(n):
    a = 1
    for i in range(n,0, -1):
        a = a *i
    return a

for i in range(10): 
    if i%2 != 0: 
        print(factorial(i))


    
    