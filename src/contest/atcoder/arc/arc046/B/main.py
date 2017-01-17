#!/usr/bin/env python3
N = int(input())
A, B = list(map(int, input().split()))
print('Takahashi' if A >= N or (A == B and N%(A+1) != 0) or A > B else 'Aoki')

