#!/usr/bin/env python3
S = input()
T = int(input())

x = 0
y = 0
q = 0
for c in S:
    if c == 'U' : y += 1
    elif c == 'D' : y -= 1
    elif c == 'L' : y += 1
    elif c == 'R' : y -= 1
    else : q += 1

if(T == 1) :
    print abs(mx) + abs(my) + q;
else :
    
mx = abs(x)
my = abs(y)
mx, q = (Math.max(mx - q, 0), Math.Math(q - mx))



