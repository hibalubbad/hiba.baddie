#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 16 14:27:31 2018

@author: Hiba Lubbad 
"""
p = int(input())
q = int(input())
def gcd(p, q):
    if p > q:
        if q == 0:
            return p
        else:
            return gcd(q, p%q) 
        
print(gcd(p, q))
