#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 16 16:03:05 2018

@author: Hiba Lubbad
"""
n = int(input())
def generatepascal(n):
    pascal = []
    pascalIndex = 0
    pascal.append([1])
    for i in range(n):
        ls = []
        ls.append(1)
        for j in range(1, len(pascal[pascalIndex])):
            ls.append(pascal[pascalIndex][j]+ pascal[pascalIndex][j-1])
        ls.append(1)
        pascalIndex +=1
        pascal.append(ls)
        
    return pascal 

def print_triangle(coeffs):
    for i in generatepascal(n):
        for j in i:
            print(j, end=' ')
        print()
    
print_triangle(generatepascal(n))
