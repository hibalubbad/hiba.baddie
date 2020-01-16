#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 21 20:19:17 2018

@author: Hiba Lubbad
"""

t = [[1,0,1],[0,1,0]]

def different(t):
    a = []
    for i in range(len(t)):
        for j in range(len(t[i])):
            if t[i][j] not in a:
                a.append(t[i][j])
    return len(a)
print(different(t))
