#!/usr/bin/env python3
S = list(input())

mp = {}
for c in S:
    if not c in mp : mp[c] = 0
    mp[c] += 1
pair = 0
single = 0
for (c, n) in mp.items():
    pair += int(n / 2)
    single += n % 2

print(int(pair / single) * 2 + 1 if single > 0 else pair * 2)
