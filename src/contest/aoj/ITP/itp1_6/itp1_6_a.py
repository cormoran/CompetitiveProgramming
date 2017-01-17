n=raw_input()
ls=map(int,raw_input().split())
ls.reverse()
ans=''
for i in range(len(ls)-1):
    print ls[i],
print ls[len(ls)-1]
