#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 25 15:18:43 2018

@author: misskeisha
"""

def is_valid(s1, s2, s3):
    return (s1 + s2 > s3 and s2 + s3 > s1 and s1 + s3 > s2)
def area(s1, s2, s3):
    s = (s1 + s2 + s3)/2
    return ((s*(s - s1)*(s - s2)*(s - s3))** 0.5)

s1 = float(input("s1 :"))
s2 = float(input("s2 :")) 
s3 = float(input("s3 :"))

if is_valid(s1, s2, s3):
    print("Valid Triangle")
    print(area(s1, s2, s3))
else:
    print("not a valid Triangle")
    
    