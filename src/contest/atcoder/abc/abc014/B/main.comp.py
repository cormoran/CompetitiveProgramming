n,X=map(int,raw_input().split())
costs=map(int,raw_input().split())
bina=bin(X).replace("0b","")
ans=0;
while(not len(bina)==n):bina="0"+bina
for i in range(n):
    if(bina[len(bina)-i-1]=='1'):ans+=costs[i]
print ans


