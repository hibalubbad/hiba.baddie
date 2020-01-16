#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Sep 22 10:41:20 2018

@author: misskeisha
"""

def last_digit(number): 
    
    return number %10
   
def nth_digit(number,n):
    return (number // (10 **(n)))% 10

for i in range(13):
    number = 2 ** i
    print(str(last_digit(number)) + str(nth_digit(number,1)))

    