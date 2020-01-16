#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 24 22:25:31 2018

@author: misskeisha
"""
def diamondup(n, c):
    for line in range(n):
        for spaces in range((n-line)-1):
            print(" ", end = "")
        print("/", end = "")
        for plus in range(0,2*line):
            print(c, end = "")
        print("\\", end = "") 
        for spaces in range((n-line)-1):
            print(" ", end = "")
        print()   

def diamonddown(n,c):
    for line in range(n):
        for spaces in range(line):
            print(" ", end = "")
        print("\\", end = "")
        for plus in range(((n - line)-1)*2):
            print(c, end = "")
        print("/", end = "") 
        for spaces in range(line):
            print(" ", end = "")
        print()

n = int(input())
c = input()
def diamond(n,c):
    diamondup(n,c)
    diamonddown(n, c)

diamond(n,c)