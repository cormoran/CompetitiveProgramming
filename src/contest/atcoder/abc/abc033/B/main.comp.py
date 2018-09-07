#!/usr/bin/env python3
N = int(input())
S =[]
P = []
for i in range(N):
    s,p = input().split()
    S += [s]
    P += [int(p)]
if any(p*2 > sum(P) for p in P):
    print(S[P.index(max(P))])
else:
    print('atcoder')
