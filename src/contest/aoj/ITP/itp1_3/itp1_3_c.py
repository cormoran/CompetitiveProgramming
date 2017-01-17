while 1:
    m,n=[int(i) for i in raw_input().split() ]
    if m==n==0:
        break
    if m>n:
        print "%d %d" % (n,m)
    else :
        print "%d %d" % (m,n)
