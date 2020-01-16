#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 16 15:09:51 2018

@author: Hiba Lubbad 
"""
 
import turtle


n = int(input())
turtle.up()
turtle.goto(0,-200)
turtle.down()
turtle.left(90)
def tree(n,length):
    if n==0:
        turtle.forward(length)
    else:
        turtle.pensize(length/10)
        tree(0,length)
        turtle.right(25)
        tree(n-1,length*0.6)
        turtle.backward(length*0.6)
        turtle.left(80)
        tree(n-1,length*0.6)
        turtle.backward(length*0.6)
        turtle.right(40)
        tree(n-1,length*0.3)
        turtle.backward(length*0.3)
        turtle.right(15)
tree(n,100)
turtle.done()
turtle.tracer(0)