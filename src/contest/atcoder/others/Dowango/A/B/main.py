#!/usr/bin/env python3
N = int(input())
K = list(map(int,input().split()))

a = [ K[0] ] + [ min(K[i], K[i+1]) for i in range(N-2)] + [ K[N-2] ]
print( ' '.join(list(map(str,a))) )
