#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 14 12:47:24 2018

@author: misskeisha
"""
import sys
lst = (sys.argv[1:])
def flatten(lst):
    nlst =  [] 
    for i in lst:
        if type(i) == list:
            nlst += flatten(i)
        else:
            nlst.append(i)
    return nlst 

print(flatten(lst))          
            
    
