#!/usr/bin/env python3
A ,B = list(map(int, input().split()))
print(int(B / A) + (B % A != 0))
