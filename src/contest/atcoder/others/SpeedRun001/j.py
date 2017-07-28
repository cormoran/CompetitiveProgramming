class Fenwick():

    def __init__(self, n):
        self.data = [0 for _ in range(n + 1)]

    def sum(self, i):  # [0, i]
        s = 0
        while i > 0:
            s += self.data[i]
            i -= i & (-i)  # ok?
        return s

    def range_sum(self, i, j):  # [i, j]
        return self.sum(j) - self.sum(i - 1)

    def add(self, i, x):
        while i < len(self.data):
            self.data[i] += x
            i += i & -i

N = int(input())
bit = Fenwick(N)
ans = 0
for a in map(int, input().split()):
    ans += bit.range_sum(a + 1, N)
    bit.add(a, 1)
print(ans)
