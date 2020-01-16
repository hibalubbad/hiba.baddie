#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  9 13:27:49 2018

@author: misskeisha
"""
import random

#n = int(input())

def deck():
    suit = ["spades", " hearts", "clubs", "diamonds"]
    rank = [ 2,3,4,5,6,7,8,9,10,"jack","ace", "king", "queen"]
    lcards = []
    for i in suit:
        for j in rank:
            lcards = lcards + [str(j) + " of "+ str(i)]
    return lcards
 


def choose_cards(n):
    listn = []
    for i in range(n):
        listn = listn+ [(random.choice(deck()))]
    return listn
def suit_count(hand):
    listcount = [0, 0 , 0, 0]
    suit = ['spades', ' hearts', 'clubs', 'diamonds']
    for i in range(len(hand)):
        for j in range(len(suit)):
            if suit[j] in hand[i]:
                listcount[j] = listcount[j] + 1
                
    return listcount
    
hand = deck()
print(suit_count(hand))

