#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 11 22:38:47 2018

@author: misskeisha
"""
num = 3
for row in range(num,0,-1):
    for col in range(0, num - row):
        print(end = ' ')
    for col in range(0, row):
        print("*",end = " ")
    print()

num = 3
for row in range(0,num):
    for col in range(0, num-row-1):
        print(end = ' ')
    for col in range(0, row+1):
        print("*",end = " ")
    print()
num = 3
for row in range(num,0,-1):
    for col in range(0, num - row):
        print(end = ' ')
    for col in range(0, row):
        print("*",end = " ")
    print()
num = 3
for row in range(0,num):
    for col in range(0, num-row-1):
        print(end = ' ')
    for col in range(0, row+1):
        print("*",end = " ")
    print()
