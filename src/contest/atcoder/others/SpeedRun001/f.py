input()
ans, mx = 0, 0
for a in map(int, input().split()):
    ans += 1 if mx < a else 0
    mx = max(mx, a)
print(ans)
