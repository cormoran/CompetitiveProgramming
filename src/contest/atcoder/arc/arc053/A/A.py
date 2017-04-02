#!/usr/bin/env python3
H , W = list(map(int, input().split()))
print(H * (W - 1) + W * (H - 1))
