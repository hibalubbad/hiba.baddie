#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Nov 10 19:47:52 2018

@author: misskeisha
"""
s = input()
def longestpalin(s):
    lenmax = 0
    startmax = 0
    for i in range(1,len(s)):
        low = i-1
        high = i
        while low >= 0 and high < len(s) and s[low] == s[high]:
            if high - low +1 > lenmax:
                lenmax = high - low +1
                startmax = low
            low -= 1
            high +=1
    longesteven = s[startmax:startmax+lenmax]
    for i in range(1,len(s)):
        low = i-1
        high = i+ 1
        while low >= 0 and high < len(s) and s[low] == s[high]:
            if high -low +1 > lenmax:
                lenmax = high - low + 1
                startmax = low
            low -= 1
            high +=1
    longestodd = s[startmax:startmax+lenmax]
    return max(longestodd, longesteven, key=len)
        
print(longestpalin(s))
