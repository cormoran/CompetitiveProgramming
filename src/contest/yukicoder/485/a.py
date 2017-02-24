#!/usr/bin/env python3
A, B = map(int, input().split())
print("NO" if A == 0 or B % A != 0 else int(B / A))
