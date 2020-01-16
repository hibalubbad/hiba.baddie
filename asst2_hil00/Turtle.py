#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 18 14:34:18 2018

@author: misskeisha
"""
import turtle
n = int(input()) #number of sides
a = int(input()) # lenght of sides 
for i in range(n):
    turtle.forward(a)
    turtle.left(360/n)
turtle.done()
