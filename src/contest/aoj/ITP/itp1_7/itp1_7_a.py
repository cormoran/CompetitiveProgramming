while 1:
    m,f,r=map(int,raw_input().split())
    if m==f==r==-1 :break
    ans=''
    if m==-1 or f==-1 :ans= 'F'
    else :
        mp=m+f
        if mp>=80:ans='A'
        elif mp>=65:ans='B'
        elif mp>=50 or (mp>=30 and r>=50):ans='C'
        elif mp>=30:ans='D'
        else :ans='F'
    print ans
