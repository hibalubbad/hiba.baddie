#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Oct  6 00:56:47 2018

@author: misskeisha
"""
import sys 

lf = list(sys.argv[1:])
def strings2floats(ls):
    new_ls = []
    for s in ls:
        new_ls.append(float(s))
    return new_ls

def positive_min(lf):
    copy = []
    for c in strings2floats(lf):
        if c >= 0:
            copy.append(c)
    return min(copy)
        
print(positive_min(lf))