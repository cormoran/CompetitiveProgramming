#!/usr/bin/env python

x, y = map(int, raw_input().split())

if x > 0:
    x1 = 0
    y2 = 0
    y1 = abs(y) + x
    x2 = y1
    if y < 0:
        y1 *= -1
elif x < 0:
    y1 = 0
    x2 = 0
    x1 = x - abs(y)
    y2 = x1
    if y > 0:
        y2 *= -1

print x1, y1, x2, y2
