s=lambda:list(map(int,input().split()))
N,Q=s()
p=[0]*N
g=lambda x:p[x] if p[x] else x
for i in range(Q):
    A,B,C=s()
    if A==1:
        print ['YES','NO'][g(B)==g(C)]
    else :
        if g(B)!=g(C):p[B]=C
        
