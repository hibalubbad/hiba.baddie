#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  2 14:05:05 2018

@author: misskeisha
"""
string = input()

def palinrome(string):
    counter = 0 
    counter2 = (len(string)-1) - counter
    while True:
        if string[counter]== string[counter2]:
            counter +=1 
            return True
        else:
            return False 

print(palinrome(string))
