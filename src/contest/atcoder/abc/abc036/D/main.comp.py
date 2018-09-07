#!/usr/bin/env python3
import math
MOD = 1000000000 + 7

N = int(input())
E = [[] for i in range(N)]
for i in range(N - 1):
    a, b = list(map(int, input().split()))
    E[a - 1].append(b - 1)
    E[b - 1].append(a - 1)

def dfs(now, pre, depth):
    ret = [1, 1] # W, B
    for nxt in E[now]:
        if nxt != pre:
            tmp = dfs(nxt, now, depth + 1)
            ret[0] = (ret[0] * sum(tmp)) % MOD
            ret[1] = (ret[1] *tmp[0]) % MOD
    return ret    
print(sum(dfs(0, -1, 0)) % MOD)

