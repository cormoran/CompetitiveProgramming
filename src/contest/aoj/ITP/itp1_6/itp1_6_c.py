n=int(raw_input())
buildings=[[[0 for i in range(10)] for j in range(3)] for k in range(4)]
for i in range(n):
    b,f,r,v=map(int,raw_input().split())
    buildings[b-1][f-1][r-1]+=v
#print buildings
for i in range(4):
    for j in range(3):
        ln=''
        for k in range(10):
            ln+=' '+str(buildings[i][j][k])
        print ln
    if i!=3:print '#'*20

