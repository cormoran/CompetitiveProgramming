#!/usr/bin/env python
L, H = map(int, raw_input().split())
for i in range(int(raw_input())):
    A = int(raw_input())
    print(max(0, L - A) if A <= H else -1)
