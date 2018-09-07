#!/usr/bin/env python3
N = int(input())
A = [int(input()) for i in range(N)]
uniq = list(set(A))
mp = {}
for (i, key) in enumerate(sorted(uniq)):
    mp[key] = i
for i in range(N):
    print(mp[A[i]])
