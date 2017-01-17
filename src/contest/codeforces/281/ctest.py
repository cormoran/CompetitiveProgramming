import random
random.seed()
f=open("./ctest.txt","w")
n=200000
m=200000
f.write(str(n)+"\n")
f.write(str(random.randint(1,2000000000)))
for i in range(0,n-1):
    f.write(" "+str(random.randint(1,2000000000)))
f.write("\n")
f.write(str(m)+"\n")
f.write(str(random.randint(1,2000000000)))
for i in range(0,m-1):
    f.write(" "+str(random.randint(1,2000000000)))
f.write("\n")
f.close()
