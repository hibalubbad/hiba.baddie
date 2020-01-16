#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  9 14:35:41 2018

@author: misskeisha
"""

passw = input()

if (any(x.isupper() for x in passw) and any(x.islower() for x in passw) and (passw.isalnum() == False) and len(passw) >= 8) and any(x.isdigit() for x in passw):
    print('good password')
else:
    print('poor password')