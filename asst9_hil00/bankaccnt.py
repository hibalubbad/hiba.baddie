#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Nov 11 12:46:50 2018

@author: misskeisha
"""

class BankAccount(object):
    ''' parameters:
        x : int
        deposit: int
        withdraw: int '''
            
    def __init__(self,x=0):
        self.x = x
    def __str__(self):
        return (str(self.x))
    def __eq__(self,other):
        ''' checks if the bankaccounts are equal'''
        if self.x == other.x:
            return True 
        else:
            return False 
    def deposite(self,deposite):
        ''' adds to the bank account nd raises an error of the amount is negative'''
        if deposite > -1:
                self.x += deposite 
        else:
            raise ValueError('Negative Deposite')
    def withdraw(self,withdraw):
        ''' subtracts from the bank account and raises an error of the amount is greater than the balance'''
        if withdraw <= self.x:
            self.x = self.x - withdraw  
        else:
            raise ValueError('Overdraft')
    def balance(self):
        ''' returns the balance in the account nd raises an error of the amount is negative'''
        if self.x > -1:
            return self.x
        else:
            raise ValueError('Illegal Balance') 
        
    
 
#x = BankAccount(550)
#c = BankAccount(667)
#x.deposite(999)
#x.withdraw(0)
#print(x.balance())
