#!/usr/bin/env python3
N = input()
S = input()
for i in range(len(S) - 1):
    if S[i] == S[i+1] :
        print('YES')
        exit(0)
print('NO' if len(S) < 4 else 'YES')
