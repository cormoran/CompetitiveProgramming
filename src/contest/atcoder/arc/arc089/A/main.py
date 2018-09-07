#!/usr/bin/env python


def check(dt, dl):
    if dt < dl:
        return False
    left = dt - dl
    return left % 2 == 0

N = int(input())
t, x, y = 0, 0, 0
for n in range(N):
    ti, xi, yi = map(int, input().split())
    dt = ti - t
    dx = xi - x
    dy = yi - y

    if not check(dt, abs(dx) + abs(dy)):
        print('No')
        exit(0)

    t, x, y = ti, xi, yi
print('Yes')
