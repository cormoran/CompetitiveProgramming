n=int(raw_input())%30
L=range(1,7)
for i in range(n):
    L[i%5],L[i%5+1]=L[i%5+1],L[i%5]
A=''
for i in range(len(L)):
    A+=str(L[i])
print A
