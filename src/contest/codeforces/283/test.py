import random
f=open("btes.txt",'w')
f.write('1000\n')
random.seed()
for i in range(0,1000):
    f.write(str(random.randint(0,9)))
f.write('\n')
f.close
