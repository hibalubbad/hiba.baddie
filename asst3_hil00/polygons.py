#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 25 18:06:38 2018

@author: misskeisha
"""

import turtle
def cpolygon(n, size):
    for i in range(n):
        if i%2 ==0:
            turtle.color("black")
        else:
            turtle.color("red")
        turtle.forward(size)
        turtle.left(360/n)
    turtle.done()
n = int(input())
size = int(input())

print(cpolygon(n, size))    
