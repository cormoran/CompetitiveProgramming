w,h,x,y,r=[int(i) for i in raw_input().split()]

if x-r<0 or x+r>w or y-r<0 or y+r>h:
    print 'No'
else :
    print 'Yes'
