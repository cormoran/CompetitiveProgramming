
n=long(raw_input())
ls=[]
for i in range(n):
    a=map(long,raw_input().split())
    a.reverse()
    ls.append(a)
ls.sort()
ans=0
vans=0
last=ls[0][0]
lastindex=0
i=0

for i in range(len(ls)):
    if ls[i][1]<=ls[lastindex][0]:vans+=1
    else :
        vvans=vans
        last=ls[lastindex][0]
        while ls[lastindex][0]<=ls[i][1]:
            lastindex+=1
            if lastindex>=len(ls):break
            vans-=1
            if vans<0 : vans=0
        ans=max(ans,vvans)
ans=max(ans,vans)
print ans
