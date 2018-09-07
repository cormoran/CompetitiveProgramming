#!/usr/bin/env python3
from heapq import heappush, heappop


def dijkstra(e, start, goal):
    INF = 10**8
    dist = [INF] * len(e)
    dist[start] = 0
    que = []
    heappush(que, (0, start))
    while len(que) > 0:
        cost, now = heappop(que)
        for nxt in e[now]:
            if dist[nxt] > cost + 1:
                heappush(que, (cost + 1, nxt))
                dist[nxt] = cost + 1
    return dist


def count(e, dist, a, b):
    cnt = [0] * len(e)
    cnt[b] = 1
    que = []
    pushed = {b: True}
    heappush(que, (-dist[b], b))
    while len(que) > 0:
        _, now = heappop(que)
        mindist = min((dist[x] for x in e[now]))
        if mindist >= dist[now]:
            continue
        for prev in e[now]:
            if dist[prev] == mindist:
                if not prev in pushed:
                    heappush(que, (-dist[prev], prev))
                    pushed[prev] = True
                cnt[prev] += cnt[now]
    # print(cnt)
    return cnt[a] % 1000000007


n = int(input())
a, b = map(int, input().split())
a -= 1
b -= 1
m = int(input())

e = [[] for i in range(n)]

for i in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    e[x].append(y)
    e[y].append(x)

# print(e)
dist = dijkstra(e, a, b)
#print("dist", dist)
print(count(e, dist, a, b))
