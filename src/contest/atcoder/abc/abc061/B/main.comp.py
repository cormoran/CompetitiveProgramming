N, M = map(int, input().split())
E = [ 0 for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    E[a - 1] += 1
    E[b - 1] += 1
 
for i in range(N):
    print(E[i])
