#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 10 22:10:01 2018

@author: misskeisha
"""
n = int(input())

def factorial(n):
    if n == 1:
        return 1
    else:
        return n*factorial(n-1)
    
print(factorial(n))