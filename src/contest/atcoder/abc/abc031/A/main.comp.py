#!/usr/bin/env python
A, D = map(int, raw_input().split())
print(max((A + 1) * D, A * (D + 1)))
