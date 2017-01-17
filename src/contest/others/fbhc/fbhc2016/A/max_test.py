#!/usr/bin/env python2
import random

T = 50

print(T)
for t in range(T):
    N = 2000
    X = [random.randint(-10000, 10000) for i in range(N)]
    Y = [random.randint(-10000, 10000) for i in range(N)]
    print(N)
    for i in range(N):
        print X[i], Y[i]
