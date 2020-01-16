#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 25 15:40:00 2018

@author: misskeisha
"""

def substring(s1, s2, k):
    return s2[k:k+len(s1)] == s1
def how_many(s1, s2):
    count = 0
    for i in range(len(s2)):
        if substring(s1, s2, i):
            count +=1
        return count
s1 = input("enter first string")
s2 = input("enter second string")
print(how_many(s1,s2))
