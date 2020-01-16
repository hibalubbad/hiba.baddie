#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 18 14:45:58 2018

@author: misskeisha
"""

m = int(input())
n = int(input())
for row in range(m):
    for col in range(n):
        print((m*col)+row, end= ' ')
    print()
