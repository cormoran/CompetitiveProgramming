import random
MAX_=100#100000
MAX_d=100#1<<60
random.seed()
f=open("./mysamp.txt","w")
n=random.randint(2,MAX_)
m=random.randint(n-1,MAX_)
f.write("%d %d\n"%(n,m))
for i in range(m):
    a=random.randint(0,n-1)
    b=random.randint(0,n-1)
    c=random.randint(0,MAX_)
    f.write("%d %d %d\n"%(a,b,c))
q=random.randint(1,100)
f.write("%d\n"%(q))
for i in range(q):
    fs=random.randint(0,MAX_d)
    fe=random.randint(0,MAX_d)
    f.write("%d %d\n"%(fs,fe))
f.close()
