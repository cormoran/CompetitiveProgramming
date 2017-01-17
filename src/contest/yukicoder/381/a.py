#!/usr/bin/env python3
import math
N = int(input())
sum = 0
max = 2 * N
flg = False
while N > 0:
    sum += N
    N = N // 2
    print(N)

print((max - sum) % 1004535809)
