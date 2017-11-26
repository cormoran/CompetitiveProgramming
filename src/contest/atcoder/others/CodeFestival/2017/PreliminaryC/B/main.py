#!/usr/bin/env python
N = int(input())
A = map(int, input().split())

all = 3 ** N
no = 1
for a in A:
    no *= 2 if a % 2 == 0 else 1
print(all - no)
