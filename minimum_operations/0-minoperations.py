#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor can execute only two operations in this file: Copy All and Paste.
Given a number n, write a method that calculates the fewest number of operations needed to result in exactly n H characters in the file.
Be smart about how you utilize the memory!
Prototype: def minOperations(n)
Returns an integer
If n is impossible to achieve, return 0
"""
def minOperations(n):
    if n > 1:
        nboperations = 0
        div = 2
        while div <= n:
            if ((n % div) == 0):
                nboperations += div
                n = n/div
            else:
                div += 1
        return (nboperations)
    else:
        return 0
