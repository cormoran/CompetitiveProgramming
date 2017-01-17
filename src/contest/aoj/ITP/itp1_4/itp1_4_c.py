while 1 :
    a,op,b=raw_input().split()
    ai=int(a)
    bi=int(b)
    if op=='?':break
    elif op=='+':print ai+bi
    elif op=='-':print ai-bi
    elif op=='*':print ai*bi 
    elif op=='/':print ai/bi 
