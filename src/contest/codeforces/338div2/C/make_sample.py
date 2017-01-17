#!/usr/bin/env python3
import random
source_str = 'abcdefghijklmnopqrstuvwxyz'
random.choice(source_str)
s = "".join([random.choice(source_str) for x in range(2100)])
print(s)
