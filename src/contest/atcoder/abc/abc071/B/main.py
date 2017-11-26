S = input()
for i in range(ord('a'), ord('z') + 1):
    if not(chr(i) in S):
        print(chr(i))
        exit()
print('None')
