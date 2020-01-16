#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 10 22:14:42 2018

@author: misskeisha
"""
st = input()


def is_palindrome(st):
    for i in range(len(st)):
        if st[i] != st[len(st)-i-1]:
            return False
    return True

def longest_palin(st): 
    maxim = '' 
    for i in range(0,len(st)):
        if len(maxim) > len(st)-1:
            break
        for j in range(i,len(st)):
            if st[i] == st[j]:
                sub = list(st[i:j +1])
            if is_palindrome(sub):
                if len(sub) > len(maxim):
                    maxim = ''.join(sub)
    return maxim

print(longest_palin(st))     