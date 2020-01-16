#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Nov 11 20:47:26 2018

@author: misskeisha
"""
import math

class Polygon(object):
    def __init__(self,n,s):
        self.n = n
        self.s = s
    def parameter(self):
        return self.n*self.s
    def area(self):
        area =  ((self.s**2)*self.n)/(4*math.tan(math.pi / self.n))    
        return area 


x = Polygon(5,3)
print(x.parameter())
print(x.area())
        