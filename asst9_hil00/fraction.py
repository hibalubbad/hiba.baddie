#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Nov 11 17:36:07 2018

@author: misskeisha
"""

def gcd(p,q):
    while p%q != 0:
        oldp = p
        oldq = q
        p = oldq
        q = oldp%oldq
    return q
class Fraction(object):
    ''' parameters:
        Num : int
        Denom: int
        '''
    def simplify(self):
        ''' method used to simplify the fraction'''
        common = gcd(self.Num,self.Denom)
        self.Num =  self.Num // common 
        self.Denom = self.Denom // common 
        return Fraction(self.Num,self.Denom)
    def __init__(self,Num,Denom):
        self.Num = Num
        self.Denom = Denom
    def __str__(self):
        return str(self.Num)+"/"+str(self.Denom)
    def __add__(self, other):
        ''' adds the fractions by taking a common denominator '''
        numerNew = other.Denom * self.Num \
                   + other.Num * self.Denom
        denomNew = other.Denom * self.Denom
        result = Fraction(numerNew, denomNew ) 
        return result.simplify()
    def __sub__(self, other):
        ''' subtracts the fractions by taking a common denominator '''
        numerNew = other.Denom * self.Num \
                   - other.Num * self.Denom
        denomNew = other.Denom * self.Denom
        result = Fraction(numerNew, denomNew ) 
        return result.simplify()
    def __mul__(self,other):
        numerNew = other.Num * self.Num
        denomNew = other.Denom * self.Denom
        result = Fraction(numerNew, denomNew ) 
        return result.simplify()
    def __lt__(self,other):
        ''' allows for comparing the fractions'''
        return (self.Num * self.Denom) < (other.Num * other.Denom)
    def __eq__(self,other):
        return (self.Num * self.Denom) == (other.Num * other.Denom)

    
#myf = Fraction(24,48)
#other = Fraction(1,2)
#print(myf.simplify())
#print(myf == other)
#print(myf*other)
#print(myf+other)
#print(myf-other)
#print(myf<other)
