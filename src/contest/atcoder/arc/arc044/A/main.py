#!/usr/bin/env python3
import math


def f(N):
    if N % 2 != 0 and N % 10 != 5:
        s = 0
        while N:
            s += N % 10
            N = int(N / 10)
        if s % 3 != 0:
            return True
    return False

N = int(input())
for n in range(2, math.floor(math.sqrt(N)) + 1):
    if N / n == int(N / n):
        print("Prime" if f(N) else "Not Prime")
        exit(0)

print("Prime" if N != 1 else "Not Prime")
