#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 18 14:21:43 2018

@author: misskeisha
"""

w = float(input())
h = float(input())
bmi = w/(h**2)
if bmi < 15:
    print('Starvation')
elif bmi < 17.5:
    print('Anorexic')
elif bmi < 18.5:
    print('Underweight')
elif 18.5<=bmi<25:
    print('Ideal')
elif 25<=bmi<30:
    print('Overweight')
elif 30<=bmi<40:
    print('Obese')
else:
    print('Morbidly Obese')
    
