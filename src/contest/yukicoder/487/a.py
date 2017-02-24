#!/usr/bin/env python
M = int(input())
ans = 1
for i in range(2017):
    ans = (ans * 2017 * 2017) % M
ans += 2017
print(ans % M)
