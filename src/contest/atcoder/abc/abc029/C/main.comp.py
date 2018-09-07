def rec(n,N,s):
    if n==N:return [s]
    ret=[]
    for i in ['a','b','c']:
        ret+=rec(n+1,N,s+i)
    return ret

ans=rec(0,int(input()),'')
for i in range(len(ans)):
    print(ans[i])
