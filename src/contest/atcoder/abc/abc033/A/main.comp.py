#!/usr/bin/env python3
S = input()
print('SAME' if all(c == S[0] for c in S) else 'DIFFERENT')


