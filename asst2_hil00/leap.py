#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 18 14:14:37 2018

@author: misskeisha
"""

year = abs(int(input()))
a = year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)
print(a) 
    