#!/usr/bin/env python
N = int(input())
if N < 9:
    print(N)
    exit(0)
n = 0
while True:
    nxt = n * 10 + 9
    if nxt > N:
        break
    n = nxt

ans = n
for i in range(1, 10):
    n1 = int(str(i) + str(n))
    if n1 <= N:
        ans = n1
s = 0
while(ans):
    s += ans % 10
    ans = ans // 10
print(s)
