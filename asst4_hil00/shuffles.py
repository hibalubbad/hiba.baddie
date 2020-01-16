#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  2 16:38:49 2018

@author: misskeisha
"""
import random, sys

lst = list(sys.argv[1:])
def shuffle(lst):
    for i in  range(len(lst)):
        rnd = random.randrange(0,len(lst))
        lst[i], lst[rnd] = lst[rnd], lst[i]
    print(' '.join(lst))

shuffle(lst)
