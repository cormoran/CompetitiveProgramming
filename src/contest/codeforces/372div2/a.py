#!/usr/bin/env python3
N, C = map(int, input().split())
T = list(map(int, input().split()))
cnt = 0
for i in range(N - 1):
    if T[i + 1] - T[i] <= C:
        cnt += 1
    else:
        cnt = 0
cnt += 1
print(cnt)
