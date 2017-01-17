#!/usr/bin/env python3
X = int(input())

factors = {}
i = 2
while i <= 1000000 and X > 1:
    if X % i == 0:
        X = int(X / i)
        if not i in factors:
            factors[i] = 0
        factors[i] += 1
    else:
        i += 1
if X > 1:
    factors[X] = 1
Y = 1

for key in factors:
    if factors[key] % 2 != 0:
        Y *= key

print(Y)
