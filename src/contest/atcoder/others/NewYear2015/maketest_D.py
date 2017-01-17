import random
random.seed(1)
f = open("./D_test.txt", "w")

f.write(str(200) + "\n")
for i in range(200):
    f.write(str(random.randint(0, 10000)) + "\n")
f.write(str(10) + "\n")
for i in range(10):
    f.write(str(random.randint(0, 10000)) + " " + str(random.randint(0, 10000)) + "\n")
f.close()
