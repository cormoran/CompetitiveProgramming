#!/usr/bin/env python3

n = int(input())
a = list(map(int,input().split()))

ans = 1
for i in a:
    ans *= i
print(ans)
