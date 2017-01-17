#!/usr/bin/env python3
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
print((x2 * y1 + x1 * y2) / (x1 + x2))
