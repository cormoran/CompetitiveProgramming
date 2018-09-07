#!/usr/bin/env python3

print(1)
for T in range(1):
    print(100, 100)
    for i in range(100):
        print(1, 1)
    for i in range(100):
        line = ""
        for j in range(100):
            if i != j:
                line += str(1) + " "
            elif i == j:
                line += str(-1) + " "
        print(line)
    for i in range(100):
        print(i + 1, (i + 2) % 100 + 1)
