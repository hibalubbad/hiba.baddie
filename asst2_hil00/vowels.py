#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Sep 22 14:06:29 2018

@author: misskeisha
"""

def is_vowel(c):
    return any(char in c for char in "aueoi") 
def is_vowel2(c):
    vowel = ["a", "i", "u", "e", "o"]
    if (c in vowel):
        return True 
    else:
        return False 
    """
    The first function is a better code as it is shorter 
    and more concise which will make it easier to edit and debug later
    """
    
def count_vowels(string):
    vowels = "aiuoe" 
    count = 0
    for i in vowels:
        for j in string:
            if i == j: 
                count +=1
    return count

a = input()
print(count_vowels(a))
    