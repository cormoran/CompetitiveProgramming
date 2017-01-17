#!/usr/bin/env python3
n, l = map(int, input().split())
s = input()
ans = 0
tab = 1
for c in s:
    tab += 1 if c == '+' else -1
    if tab > l :
        ans += 1
        tab = 1

print(ans)
