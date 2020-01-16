#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  2 15:32:48 2018

@author: misskeisha
"""
n = int(input())
size = int(input())
color = ["green", "blue" , "yellow", "red", "pink", "purple"]
import turtle, random
def draw_square(size):
    for i in range(4):
        turtle.forward(size)
        turtle.left(90) 
def draw_grid(n, size):
    for row in range(n):
        for col in range(n):
            turtle.up()
            turtle.setpos(col*size, -row*size)
            turtle.down()
            draw_square(size)

def dot_grid(n, size):
   turtle.shape("circle")
   for row in range(n):
        for col in range(n):
            turtle.up()
            turtle.setpos(col*size + size/2, size/2 -row*size)
            turtle.down()
            if (row+col)%2 ==0:
                turtle.color("black")
                turtle.stamp()
            else:
                turtle.color("red")
                turtle.stamp()

def cdot_grid(n, size,color):
    turtle.shape("circle")
    for row in range(n):
        for col in range(n):
            turtle.up()
            turtle.setpos(col*size + size/2, size/2 -row*size)
            turtle.down()
            turtle.stamp()
            turtle.color(color[random.randint(0,len(color)-1)])
turtle.speed(200)
draw_grid(n, size)
cdot_grid(n, size,color)
#dot_grid(n, size)
