while 1:
    h,w=map(int,raw_input().split())
    if h==w==0:break
    for i in range(h):
        ln=''
        for j in range(w):
            if i%2==0:
                if j%2==0:ln+='#'
                else :ln+='.'
            else :
                if j%2==0:ln+='.'
                else :ln+='#'
        print ln
    print ''
