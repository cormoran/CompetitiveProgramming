memo = {}


def L(n):
    if n in memo:
        return memo[n]
    if n == 0:
        return 2
    if n == 1:
        return 1
    memo[n] = L(n - 1) + L(n - 2)
    return memo[n]

print(L(int(input())))
