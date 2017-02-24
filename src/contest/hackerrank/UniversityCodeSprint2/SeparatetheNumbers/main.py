#!/usr/bin/env python3
import math
import sys


def ndigit(x):
    return int(math.log10(x)) + 1 if x > 0 else 1


def query(s):
    for i in range(1, int(len(s) / 2) + 1):
        if s[0] == '0':
            continue
        n = int(s[:i])

        pos = i
        ok = True
        while pos < len(s) and ok:
            if s[pos] == '0':
                ok = False
            l = ndigit(n)
            nn = int(s[pos:pos + l])
            if n + 1 != nn:
                l += 1
                nn = int(s[pos:pos + l])
                if n + 1 != nn:
                    ok = False
            pos += l
            n += 1
        if ok:
            print('YES {0}'.format(s[:i]))
            return
    print('NO')

q = int(input())
for _ in range(q):
    s = input()
    query(s)
