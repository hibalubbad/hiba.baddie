#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Nov 11 20:08:48 2018

@author: misskeisha
"""
'''
this program takes a number as an input for number of fraction 
the class Function created in the file fraction is used to create the fractions 
the output is a list of n fractions 
'''
import random
from fraction import Fraction
n = int(input('number of fractions: '))

fractions = []
for i in range(n):
    num = random.randint(1,100)
    denom = random.randint(1,100)
    fractions += [Fraction(num,denom)]

for fraction in fractions:
	print(fraction, end=' ')
print()


fractions.sort()

for fraction in fractions:
	print(fraction, end=' ')
print()
