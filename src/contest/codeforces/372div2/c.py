#!/usr/bin/env python3
N = int(input())

for i in range(1, N + 1):
    a = 2 if i == 1 else i * (i - 1)
    b = i * i * (i + 1) * (i + 1)
    print(int((b - a) / i))
