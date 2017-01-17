s=int(raw_input())
h=s/3600
s-=h*3600
m=s/60
s-=m*60
print "%d:%d:%d" % (h,m,s)
