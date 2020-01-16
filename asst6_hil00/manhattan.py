#!/usr/bin/env python3
# -*- coding: utf-8 -*-


"""
Created on Sun Oct 21 21:22:41 2018

@author: Hiba Lubbad
"""
import random 
row = int(input())
col = int(input())
def manhattan(row,col):
    res=[]
    for i in range(row):
        res.append([])
    for i in res:
        for j in range(col):
            i.append(0)
    position=(row//2,col//2)
    z=position[0]
    w=position[1]

    while z!=-1 and z!=row and w!=-1 and w!=col:
        res[z][w] += 1
        direction=random.randrange(1,5)
        if direction==1:
            w+=1
        elif direction==2:
            z+=1
        elif direction==3:
            w-=1
        else:
            z-=1
    for i in res:
        print(i)
manhattan(row,col)
                
            
