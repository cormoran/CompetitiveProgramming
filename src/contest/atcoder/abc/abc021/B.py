n = int(raw_input())
a, b = map(int, raw_input().split())
k = int(raw_input())
P = map(int, raw_input().split())
visited = set([a, b])
for p in P:
    if p in visited:
        print("NO")
        exit(0)
    else:
        visited.add(p)
print("YES")
