#!/usr/bin/env python3
import fractions
N = int(input())
Z = list(map(int, input().split()))
G = fractions.Fraction(1, 1);
for i in range(N - 1):
    G *= fractions.Fraction(Z[i + 1], Z[i])
print(str(G.numerator) + '/' + str(G.denominator))
