#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Nov 10 15:49:30 2018

@author: misskeisha
"""
import random, operator

l = ['whole','male','trash','kay', 'bow']

def quicksort(l, low, high, compare):
	if low < high:
		pivot = partition(l, low, high,compare)
		quicksort(l, low, pivot-1,compare)
		quicksort(l, pivot+1, high,compare)
	
	return l
def partition(l,low, high,compare):
    random_index = random.randint(low,high)
    l[high], l[random_index] = l[random_index], l[high]
    pivot = low
    for i in range(low,high):
        if compare(l[i],l[high]):
            l[i],l[pivot] = l[pivot],l[i]
            pivot += 1
    l[pivot],l[high] = l[high],l[pivot]
    
    return pivot
    
    
print(quicksort(l,0, len(l)-1,compare = operator.gt))


""" We expect the function to be a complecity of O(nlogn) when the list is of size n/2 
so the equation will have a and b of value 2 and f(n) will be O(n)"""

"""yes it can experience O(n^2) behavior. In the most unbalanced case, a single quicksort call 
involves O(n) work plus two recursive calls on lists of size 0 and n−1, so the recurrence relation is
T(n) = O(n) + T(0) + T(n-1)
T(n-1) = O(n) + T(n-2)
.....
T(1) 
so, 
T(n) = O(n+n-1+n-2+ ....) = O(n^2)"""


