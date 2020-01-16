#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 22 00:29:48 2018

@author: Hiba Lubbad
"""
animals = { 'a': ['horse'], 'b': ['baboon'], 'c': ['giraffe']}
animals['d'] = ['donkey']
animals['d'].append('dog')
animals['d'].append('dingo')

def howmany(di):
    count = 0
    for i in di.values():
        count += len(i)
    return count
def biggest(di):
    l = []
    for i in di:
        a = di.get(i)
        if len(a) > len (l):
            l = a
    return l
def dstats(di):
    a,l = howmany(di), len(biggest(di))
    return (a,l)

print(dstats(animals))
