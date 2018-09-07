#!/usr/bin/env python
a, b, c, d = map(int, input())

for i in [1, -1]:
    for j in [1, -1]:
        for k in [1, -1]:
            if a + i * b + j * c + k * d == 7:
                def op(x):
                    return '+' if x == 1 else '-'
                print(str(a) + op(i) + str(b) + op(j) + str(c) + op(k) + str(d) + '=7')
                exit()
