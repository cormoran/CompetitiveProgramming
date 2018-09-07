A =int(input())
ans=0
for x in range(1,A):
    ans=max(ans,x*(A-x))
print(ans)
