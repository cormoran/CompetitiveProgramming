S = input()
s = sorted([S.count('a'), S.count('b'), S.count('c')])
print('YES' if s[2] - s[0] <= 1 else 'NO')
