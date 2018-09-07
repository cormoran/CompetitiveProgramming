N = input()
for i in range(10):
    if str(i) * 3 in N:
        print('Yes')
        exit()
print('No')
