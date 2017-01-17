#!/usr/bin/env python3

N = int(input())
A = map(int, input().split())

INF = 1e8
pre = -INF
d = INF
for a in sorted(A):
    if pre != a:
        d = min(d, a - pre)
    pre = a

print(d if d < INF else 0)
