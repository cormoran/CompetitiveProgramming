from collections import deque
N = int(input())
ans, sum = 0, 0
que = deque()
for a in map(int, input().split()):
    sum += a
    que.append(a)
    while sum > N:
        sum -= que.popleft()
    ans += 1 if sum == N else 0
print(ans)
