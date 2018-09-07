#!/usr/bin/env python3
N = int(input())
A = list(map(int, input().split()))

def sum(A,l,r):
    ret1 = 0
    ret2 = 0
    
    for i in range(r-l+1):
        if i % 2 == 0 : ret1 += A[i+l]
        else : ret2 += A[i+l]
    return ret1,ret2
            
ans = -999999999
for i in range(N):
    a = -99999999
    t = -99999999
    for j in range(N):
        if i == j : continue
        tmp = 0
        l = min(i,j)
        r = max(i,j)
        tt,ta = sum(A,l,r)
        if ta > a:
            t = tt
            a = ta
    ans = max(ans, t)

print(ans)
