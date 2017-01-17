#!/usr/bin/env python3
d = int(input())
H = [ int(input()) for i in range(3)]

if d == 0:
    print(-1 if (H[0] == H[1] or H[1] == H[2]) or min(H) != H[1] and max(H) != H[1] else 0)
else :
    mx = max(H)
    
