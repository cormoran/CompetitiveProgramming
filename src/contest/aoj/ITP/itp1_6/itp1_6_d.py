n,m=map(int,raw_input().split())
a=[]
for i in range(n):
    a.append([int(v) for v in raw_input().split()])
b=[]
for i in range(m):
    b.append(int(raw_input()))
for i in range(n):
    ans=0
    for j in range(m):
        ans+=a[i][j]*b[j]
    print ans
