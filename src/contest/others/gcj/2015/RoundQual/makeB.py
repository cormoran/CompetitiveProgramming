f=open("./B_largebymyself.txt","w")
f.write('1\n')
f.write('1000\n')
st=""
for i in range(1000):
    st=st+str(i)+' '
f.write(st+'\n')
f.close()
