#!/usr/bin/env python3

N = int(input()) + 1
ans = ""
A = ord("A")
while N > 0:
    d = (N - 1) % 26
    N = int((N - 1) / 26)
    ans += chr(A + d)
print(ans[::-1])
