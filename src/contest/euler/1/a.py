#!/usr/bin/env python3

ans = 0
for i in range(1, 1000, 1):
    if i % 3 == 0 or i % 5 == 0:
        ans += i
print(ans)
