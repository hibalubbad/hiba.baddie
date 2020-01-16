#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  2 14:56:40 2018

@author: misskeisha
"""

number = input("think of an integer between one and a thousand")
low = 1
high = 1000
while high >= low:
    print("My number is less than or equal to" + str((high + low) // 2)) 
    request = input()
    if request == "True": 
        high = (high + low) // 2
    else:
        low =  (high + low) // 2 + 1
    if high == low:
        print(" your number is:", high)
        break
            
