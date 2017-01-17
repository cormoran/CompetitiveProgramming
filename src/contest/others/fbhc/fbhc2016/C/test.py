#!/usr/bin/env python
import random
T = 40
N = 100000
print T
for i in range(N):
    print N, random.randint(1, 1000000000)
    for j in range(N):
        print random.randint(1, 1000000000),
    print ""
