
def solve(N):
    A = list(map(int, input().split()))
    ans = 1e9
    for i in range(N):
        for j in range(N):
            if i != j:
                d = abs(A[i] - A[j])
                if ans > d:
                    ans = d
    print(ans)

while True:
    N = int(input())
    if N > 0:
        solve(N)
    else:
        break
