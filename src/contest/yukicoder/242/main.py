#!/usr/bin/env python3
N = int(input())

a = 1
if N >= 5:
    for i in range(5):
        a *= N - i
        a /= 99 - i
else:
    a = 0
print(round(a * 12, 10))
