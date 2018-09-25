#!/usr/bin/env python
f = lambda: map(int, input().split())
N, M, X, Y = f()
XS = sorted(f())
YS = sorted(f())

print('War' if XS[-1] >= YS[0] or max(X, XS[-1]) >= min(Y, YS[0]) else 'No War')
