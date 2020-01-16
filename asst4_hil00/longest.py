#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  2 14:27:57 2018

@author: misskeisha
"""
string = input()
def long(string):
    maxim = " "
    current = string[0]
    for i in range(1,len(string)):
       if string[i] >= string[i-1]:
           current = current + string[i] 
     
       else:
           if len(current) > len(maxim):
               maxim = current 
               current = string[i]      
    return maxim
               
print("longest string in alphabetical order is:", long(string))     
        