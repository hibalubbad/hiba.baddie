#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 14 11:53:10 2018

@author: misskeisha
"""
import turtle

order = int(input())
length = int(input())
def fractal(order, length):
    if order == 0:
        turtle.forward(length)
    else: 
        for  i in [60, -120, 60,0]:
            fractal(order-1, length/3)
            turtle.left(i) 

def snowflake(order, length):
        fractal(order, length)
        turtle.left(-120)
        fractal(order, length)
        turtle.right(120)
        fractal(order, length)
        
turtle.speed(200)
snowflake(order, length)