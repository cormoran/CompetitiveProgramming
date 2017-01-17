#!/usr/bin/env python3
import copy

n = int(input())
days = 'x' * 20 + input() + input() + 'x' * 20

ans = 0

for i in range(len(days)):
    day2 = list(copy.copy(days))
    for j in range(n):
        if i + j < len(day2):
            if day2[i + j] == 'o':
                break
            day2[i + j] = 'o'
    ans = max(ans, max(map(lambda x: len(x), "".join(day2).split('x'))))

print(ans)
