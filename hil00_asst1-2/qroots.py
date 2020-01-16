#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 11 22:18:52 2018

@author: misskeisha
"""

a = float(input())
b = float(input())
c = float(input())
root = (b**2) - (4*a*c)
if root >= 0:
    import math 
    x,y = (-b + ( math.sqrt(root)))/ (2*a ) , (-b - (math.sqrt(root)))/ (2*a ) 
    print(x,y)
    
else:
    print("no real roots exist")