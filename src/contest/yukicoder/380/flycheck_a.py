#!/usr/bin/env python3

import sys
import re

suffix = '[^a-z0-9]?' * 3 + '$'

for line in sys.stdin:
    words = line[:-1].split(' ')
    p = words[0]
    serifu = ' '.join([s.lower() for s in words[1:]])
    flg = False
    if len(serifu) > 0:
        if p == 'digi':
            flg |= re.match('^.*nyo' + suffix, serifu) != None
        elif p == 'petit':
            flg |= re.match('^.*nyu' + suffix, serifu) != None
        elif p == 'rabi':
            flg |= re.match('.*[a-z0-9]', serifu) != None
        elif p == 'gema':
            flg |= re.match('^.*gema' + suffix, serifu) != None
        elif p == 'piyo':
            flg |= re.match('^.*pyo' + suffix, serifu) != None
    if flg:
        print('CORRECT (maybe)')
    else:
        print('WRONG!')
