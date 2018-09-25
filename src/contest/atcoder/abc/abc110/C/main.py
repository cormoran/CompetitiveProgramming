#!/usr/bin/env python
S = input()
T = input()
map_table = {}
imap_table = {}
fail = False
for i, c in enumerate(S):
    if S[i] not in map_table and T[i] not in imap_table:
        map_table[S[i]] = T[i]
        imap_table[T[i]] = S[i]
    if S[i] not in map_table or map_table[S[i]] != T[i]:
        fail = True
        break
    if T[i] not in imap_table or imap_table[T[i]] != S[i]:
        fail = True
        break
print('No' if fail else 'Yes')
