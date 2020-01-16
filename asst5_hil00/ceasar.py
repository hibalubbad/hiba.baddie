#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  9 15:14:00 2018

@author: misskeisha
"""
import sys 
k = int(sys.argv[1])
string = str(sys.argv[2:])

def shift(k,char):
    value = ord(char) + k
    new_char = chr(value)
    return new_char 

def ceasar(k,string):
    lstring = list(string)
    nstring = []
    for i in range(len(lstring)):
        if lstring[i].isupper() or lstring[i].islower():
            nstring = nstring + [shift(k,lstring[i])]
        else:
            nstring.append(lstring[i])
    return ''.join(nstring)

print(ceasar(k,string))
