n=int(raw_input())
ls=[int(i) for i in raw_input().split()]
ls.sort()
print ls[0],
print ls[len(ls)-1],
sum=0
for j in ls:
    sum+=j
print sum
