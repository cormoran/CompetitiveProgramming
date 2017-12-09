#!/usr/bin/env python
a, b = map(int, input().split())
S = input()
print('YES' if a <= len(S) and len(S) <= b else 'NO')
