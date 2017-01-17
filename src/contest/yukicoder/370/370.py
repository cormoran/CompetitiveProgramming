#!/usr/bin/env python3
N, M = map(int, input().split())
D = sorted([int(input()) for i in range(M)])
ans = 999999
for i in range(M - N + 1):
    l = i
    r = i + N - 1
    a = abs(D[r] - D[l])
    a += min(abs(D[r]), abs(D[l]))
    ans = min(a, ans)

print(ans)
