#!/usr/bin/env python3


def calc(t, a, b):
    mx = -1
    mn = 1e16
    for i in range(len(a)):
        v = a + b * t
        mx = v if v > mx else mx
        mn = v if v < mn else mn
    return mx - mn

N = int(input())
a = [0] * N
b = [0] * N
for i in range(N):
    a[i], b[i] = list(map(int, input().split()))


l = 0
r = int(1e9 * 2)
cnt = 1000
while l + 1 < r and cnt > 0:
    m = int((l + r) / 2)
    if calc(m, a, b) > calc(m + 1, a, b):
        l = m
    else:
        r = m
    cnt -= 1

print(r)
