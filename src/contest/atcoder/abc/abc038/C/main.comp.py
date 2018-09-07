#!/usr/bin/env python3
N = int(input())
A = list(map(int, input().split()))
seq = 1
ans = 1
for i in range(N - 1):
    seq = 1 + ((A[i + 1] > A[i]) and seq)
    ans += seq
print(ans)
