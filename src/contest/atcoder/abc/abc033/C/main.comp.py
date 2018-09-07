#!/usr/bin/env python3
S = input().split('+')
print(len(S) - sum('0' in s for s in S))
