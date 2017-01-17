while 1:
    h,w=map(int,raw_input().split())
    if h==w==0:break
    print '#'*w
    for i in range(h-2):
        if w>=2:
            print '#'+'.'*(w-2)+'#'
        else :
            print '#'
    print '#'*w
    print''
