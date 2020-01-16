#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 22 00:30:08 2018

@author: misskeisha
"""
moves = []
def towers(orig, dest, aux, n):
    if n == 1:
        moves.append((orig,dest))
    else:
        towers(orig, aux, dest, n-1)
        towers(orig, dest, aux,1)
        towers(aux, dest, orig, n-1)
towers('A', 'B', 'C', 3)
print(moves)