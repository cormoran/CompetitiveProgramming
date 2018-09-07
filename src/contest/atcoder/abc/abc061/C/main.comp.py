N, K = map(int, input().split())
A = {}
for _ in range(N):
    a, b = map(int, input().split())
    if not a in A:
        A[a] = 0
    A[a] += b

c = 0
for a in sorted(A.keys()):
    c += A[a]
    if c >= K:
        print(a)
        break
