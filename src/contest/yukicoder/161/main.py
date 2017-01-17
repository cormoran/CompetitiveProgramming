#!/usr/bin/env python3
G, C, P = list(map(int,input().split()))
S = input()
eG = 0
eC = 0
eP = 0
ans = 0
for c in S:
    if c == 'G' :
        if P > 0 :
            ans += 3
            P -= 1
        else :
            eG += 1
    if c == 'C' :
        if G > 0 :
            ans += 3
            G -= 1
        else :
            eC += 1
    if c == 'P' :
        if C > 0 :
            ans += 3
            C -= 1
        else :
            eP += 1
ans += min(eG, G)
ans += min(eC, C)
ans += min(eP, P)

print(ans)
