#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 21 20:26:18 2018

@author: Hiba Lubbad
"""


month = input()
day = int(input())

d ={"jan":31, "feb":28, "mar":30, "may":31, "jun":30, "jul":31, "aug":30, "sep":30, "oct":31, "nov":30, "dec":31}
counter = day

for i in d:
    if i == month:
        break
    else:
        counter += d[i]
    
print("Day of the Year:", counter)
