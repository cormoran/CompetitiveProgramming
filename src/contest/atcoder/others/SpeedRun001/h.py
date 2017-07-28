import bisect
input()
lis = []
for a in map(int, input().split()):
    flg = False
    i = bisect.bisect_right(lis, a)
    if i < len(lis):
        lis[i] = a
    else:
        lis.append(a)
print(len(lis))
