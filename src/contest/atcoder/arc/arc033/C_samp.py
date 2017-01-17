f = open("./c_samp.txt", "w")
st = "200000\n"
for i in range(100000):
    st += "1 " + str(i) + "\n"

for i in range(100000):
    st += "2 " + str(i) + "\n"
f.write(st)
f.close()
