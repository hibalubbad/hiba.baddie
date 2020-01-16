#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 18 15:22:05 2018

@author: misskeisha
"""
n = int(input())
for row in range(n):
    for col in range(0, row):
        print(".", end = ' ')
    for col in range (n-row):
        print('*', end = ' ')
    print()
        
        