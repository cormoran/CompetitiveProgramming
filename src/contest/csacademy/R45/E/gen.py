def palindromes(s):
    palindromes_set = set()
    for i in range(len(s)):
        left = i
        right = i
        while 0 <= left and right < len(s) and s[left] == s[right]:
            palindromes_set.add(s[left:right + 1])
            left -= 1
            right += 1
        left = i
        right = i + 1
        while 0 <= left and right < len(s) and s[left] == s[right]:
            palindromes_set.add(s[left:right + 1])
            left -= 1
            right += 1
    return palindromes_set


def gen(n):
    a = [""]
    if n > 0:
        a = gen(n - 1)
    res = []
    for s in a:
        res.append(s + "0")
        res.append(s + "1")
    return res


def main():
    n = 8
    a = gen(n - 1)
    for s in a:
        i = len(palindromes(s))
        print(i, s)

if __name__ == '__main__':
    main()
