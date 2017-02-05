import sys
if len(sys.argv)!=2 :
    print("Input Error")
    quit()

f=open("./test.txt","w")
for i in range(int(sys.argv[1])):
    f.write(str(i)+'\n')
f.close
