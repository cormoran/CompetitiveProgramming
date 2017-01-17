#!/usr/bin/env python
p = 3
k = 2
l = []
r = []
for i in range(p):
    r += [i]
    l += [k * i % p]
print(l)

for i in range(p):
    if r[i] != l[i]:
        print(r[i])
