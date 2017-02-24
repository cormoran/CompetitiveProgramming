#!/usr/bin/env python3
S = input()
ans = None
for i in range(2, len(S)):
    if ans is None and S[i - 2] == S[i - 1] and S[i - 1] == S[i]:
        ans = S[i]
if ans is None:
    print("NA")
else:
    print("East" if ans == "O" else "West")
