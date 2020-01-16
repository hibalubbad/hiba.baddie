#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 24 23:42:47 2018

@author: misskeisha
"""

def is_palindrome(st):
    for i in range(len(st)):
        if st[i] != st[len(st)-i-1]:
            return False
    return True

st = input()
print(is_palindrome(st))