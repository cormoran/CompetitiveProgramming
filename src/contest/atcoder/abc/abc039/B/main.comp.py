#!/usr/bin/env python3
N = int(input())
i = 1;
while(True):
    if i ** 4 == N:
        print(i)
        exit(0)
    i += 1
