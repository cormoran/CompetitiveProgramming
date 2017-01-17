#!/usr/bin/env python3
a, b = input().split();
if len(a) != len(b) :
    print(a if len(a) > len(b) else b)
elif a == b :
    print(a) # ないはず
else :
    s = ['4', '7']
    for i in range(len(a)):
        if a[i] == b[i] : continue
        if a[i] in s and b[i] in s:            
            print(a if a[i] < b[i] else b)
            exit(0)
        else :            
            print(a if a[i] > b[i] else b)
            exit(0)
