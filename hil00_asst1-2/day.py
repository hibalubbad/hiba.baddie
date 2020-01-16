#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 10 20:12:39 2018

@author: misskeisha
"""
y = int(input())
m =int(input())
d = int(input())
y0 = y - ((14 - m )//12)
x = y0 + (y0//4 )- (y0//100) + (y0 //400)
m0 = m + (12 * ((14 - m )// 12)) - 2
d0 = (d + x + ((31 * m0)// 12)) % 7
print(d0) 