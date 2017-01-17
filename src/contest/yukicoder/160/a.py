#!/usr/bin/env python3
N, M, S, G = map(int, input().split())

E = [[]] * N

for i in range(M):
    a, b, c = map(int(input().split()))
    E[a].append([b, c])
    E[b].append([a, c])
