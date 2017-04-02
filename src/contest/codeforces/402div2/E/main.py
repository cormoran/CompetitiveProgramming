#!/usr/bin/env python3
from copy import deepcopy
AND = 0
OR = 1
XOR = 2
INT = 3

N, M = list(map(int, input().split()))
variables_dict = {}
variables = []
op1 = []
op2 = []
op = []
for i in range(N):
    l = input().split()
    variables.append(l[0])
    variables_dict[l[0]] = i
    op1.append(l[2])
    ope = INT
    if len(l) == 5:
        if l[3] == 'AND':
            ope = AND
        elif l[3] == 'OR':
            ope = OR
        elif l[3] == 'XOR':
            ope = XOR
        op.append(ope)
        op2.append(l[4])
    else:
        op.append(ope)
        op2.append(None)
# => bit[m] = 0, bit[m] = 1


def calc_and(op1, op2):
    if op1 == '?' and op2 == '?':
        return (0, 1)
    elif op1 == '?':
        return (0, 1) if op2 == '1' else (0, 0)
    elif op2 == '?':
        return (0, 1) if op1 == '1' else (0, 0)
    else:
        return (1, 1) if op1 == '1' and op2 == '1' else (0, 0)


def calc_or(op1, op2):
    if op1 == '?' and op2 == '?':
        return (0, 1)
    elif op1 == '?':
        return (1, 1) if op2 == '1' else (0, 1)
    elif op2 == '?':
        return (1, 1) if op1 == '1' else (0, 1)
    else:
        return (1, 1) if op1 == '1' or op2 == '1' else (1, 1)


def calc_xor(op1, op2):
    if op1 == '?' and op2 == '?':
        return (0, 0)
    elif op1 == '?':
        return (1, 0) if op2 == '1' else (0, 1)
    elif op2 == '?':
        return (1, 0) if op1 == '1' else (0, 1)
    else:
        return (0, 0) if op1 == op2 else (1, 1)


def get_value(op, values, m):
    if op in values:
        return values[op]
    elif op is not None:
        return op[m] if len(op) > 1 else op
    return None


ans_max = ""
ans_min = ""
for m in range(M):
    one = 0
    zero = 0
    values_zero = {}
    values_one = {}
    for j in range(N):
        val = variables[j]
        ao, bo = get_value(op1[j], values_one, m), get_value(
            op2[j], values_one, m)
        az, bz = get_value(op1[j], values_zero, m), get_value(
            op2[j], values_zero, m)
        if op[j] == INT:
            if op1[j] == '?':
                values_one[val] = '1'
                values_zero[val] = '0'
            else:
                if op1[0] == '0' or op1[0] == '1':
                    values_one[val] = op1[0][m]
                    values_zero[val] = op1[0][m]
                else:
                    values_one[val] = ao
                    values_zero[val] = az
        elif op[j] == AND:
            _, o = calc_and(ao, bo)
            z, _ = calc_and(az, bz)
            one += o
            zero += z
            values_one[val] = '1' if o == 1 else '0'
            values_zero[val] = '1' if z == 1 else '0'
        elif op[j] == OR:
            _, o = calc_or(ao, bo)
            z, _ = calc_or(az, bz)
            one += o
            zero += z
            values_one[val] = '1' if o == 1 else '0'
            values_zero[val] = '1' if z == 1 else '0'

        elif op[j] == XOR:
            _, o = calc_xor(ao, bo)
            z, _ = calc_xor(az, bz)
            one += o
            zero += z
            values_one[val] = '1' if o == 1 else '0'
            values_zero[val] = '1' if z == 1 else '0'
            #print(zero, one, values_zero, values_one)
    ans_min += ('0' if zero <= one else '1')
    ans_max += ('0' if zero >= one else '1')
print(ans_min)
print(ans_max)
