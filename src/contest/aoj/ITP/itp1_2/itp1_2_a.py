c,d= raw_input().split()
a=int(c)
b=int(d)
w=" == "
if a<b:
    w=" < "
elif a>b:
    w=" > "
print 'a'+w+'b'
