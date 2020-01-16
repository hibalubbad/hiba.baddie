#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct  7 17:35:15 2018

@author: misskeisha
"""

import turtle,random
n = int(input())
size = int(input())
colors = ['green', 'yellow', 'blue', 'brown', 'red', 'pink']
def cpolygon(n, size, colors):
    for i in range(n):
        k = random.randrange(0, len(colors))
        turtle.color(colors[k])
        turtle.forward(size)
        turtle.left(360/n)
    turtle.done
cpolygon(n, size, colors)
