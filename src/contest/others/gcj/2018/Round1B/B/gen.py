#!/usr/bin/env python
import random

T = 60
print(T)
for _ in range(T):
    S = 100
    D = [random.randint(1, 1e6) for _ in range(S)]
    A = [random.randint(1, 1e6) for _ in range(S)]
    B = [random.randint(1, 1e6) for _ in range(S)]
    print(S)
    for i in range(S):
        print(D[i], A[i], B[i])
