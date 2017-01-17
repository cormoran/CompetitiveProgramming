#!/usr/bin/env python3

l,r,k = map(int,input().split())

n = 1
ans = []
while n <= r:
    if n >= l:
        ans.append(n)
    n*=k

if len(ans) > 0:
    print(' '.join(map(str,ans)))
else:
    print(-1)
