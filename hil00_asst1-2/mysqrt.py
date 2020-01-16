#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 11 18:21:21 2018

@author: misskeisha
"""

a = float(input()) 
answ = 0 
x = a 
while abs(a-(x**2))>= 10**-7:
    x = (x +a/x)/2
print(x)


