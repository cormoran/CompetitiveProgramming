#!/usr/bin/env python3
from functools import reduce
N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
sum = 0
k = 1
for i in range(N):
    sum += A[i] * k
    if i < K - 1 : k = min(K, k + 1)
    if N - i - 1 < K : k = min(K, k - 1)
print(sum)
