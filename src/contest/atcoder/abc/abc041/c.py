#!/usr/bin/env python3
input()
A = {}
for i, h in enumerate(map(int, input().split())):
    A[i] = h
for k, v in reversed(sorted(A.items(), key=lambda x: x[1])):
    print(k + 1)
