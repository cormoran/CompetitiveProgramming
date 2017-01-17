f = open("./etest.txt", 'w')
n = 100000
f.write('1 ' * 25 + '1' + '\n')
f.write('a' * n + '\n')
f.close()
