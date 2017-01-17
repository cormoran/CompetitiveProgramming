#!/usr/bin/env python3
import math
N = int(input())
C = input().split()
ops = {'+' : 0, '-' : 0}
op = 0
nums = [0] * 10
for c in C:
    if c in ops:
        ops[c] += 1
        op += 1
    else :
        nums[int(c)] += 1
num = N - op

nums_copy = list(nums)

numbers = [0] * (op + 1)
pos = 0
for i in range(op):
    while nums[pos] == 0 :
        pos += 1
    numbers[i] = pos
    nums[pos] -= 1
# 最大
a = 1
while True:
    while pos < 10 and nums[pos] == 0 :
        pos += 1
    if pos >= 10 :
        break
    numbers[-1] += pos * a
    nums[pos] -= 1
    a *= 10
numbers.reverse()
#print(numbers)
max_ans = sum(numbers[:(ops['+'] + 1)]) - sum(numbers[(ops['+'] + 1):])
min_ans = - sum(numbers[:ops['-']]) + sum(numbers[(ops['-']):])

if ops['-'] == 0:
    numbers = [0] * (op + 1)
    pos = 0
    nums_copy.reverse()
    for i in range(op):
        while nums_copy[pos] == 0 :
            pos += 1
        numbers[i] = 9 - pos
        nums_copy[pos] -= 1
    a = 1
    while True:
        while pos < 10 and nums_copy[pos] == 0 :
            pos += 1
        if pos >= 10 :
            break
        numbers[-1] += (9 - pos) * a
        nums_copy[pos] -= 1
        a *= 10
    min_ans = - sum(numbers[:ops['-']]) + sum(numbers[(ops['-']):])
print(max_ans, min_ans)
