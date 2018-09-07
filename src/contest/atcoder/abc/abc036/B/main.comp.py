#!/usr/bin/env python3
N = int(input())
S = [input() for i in range(N)]
for y in range(N):
    for x in range(N):
        print(S[N - x - 1][y], end="")
    print("")
