a, b, c = map(int, input().split())
print('YES' if (a * 100 + b * 10 + c) % 4 == 0 else 'NO')
