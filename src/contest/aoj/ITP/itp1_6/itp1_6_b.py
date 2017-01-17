n=int(raw_input())
s=range(1,14)
h=range(1,14)
c=range(1,14)
d=range(1,14)

for i in range(n):
    hd,r=raw_input().split()
    if hd=='S':
        s[int(r)-1]=0
    elif hd=='H':
        h[int(r)-1]=0
    elif hd=='C':
        c[int(r)-1]=0
    elif hd=='D':
        d[int(r)-1]=0

a='S '
for i in range(13):
    if s[i]!=0:
        print a +str(s[i])
a='H '
for i in range(13):
    if h[i]!=0:
        print a +str(h[i])
a='C '
for i in range(13):
    if c[i]!=0:
        print a +str(c[i])
a='D '
for i in range(13):
    if d[i]!=0:
        print a +str(d[i])

