#!/usr/bin/env python3

N, M = map(int, input().split())
X = list(map(int, input().split()))
Y = list(map(int, input().split()))
MOD = 1000000000 + 7
sub = 0
for i in range(N - 1):
    sub += (i + 1) * (N - i - 1) * (X[i + 1] - X[i])
    sub %= MOD
ans = 0
for i in range(M - 1):
    ans += (i + 1) * (M - i - 1) * (Y[i + 1] - Y[i])
    ans %= MOD
ans *= sub
print(ans % MOD)
