#データセットをダウンロードしてきてこのフォルダに解凍して使う
import commands

for i in range(0,48):
    print 'start '+str(i)
    fname=str(i)
    if i<10:
        fname='0'+fname
    ans=commands.getoutput("./a.out < "+"./icpc2014-dataset/G/"+fname+".in").split('\n')
#    print ans.split('\n')
    f=open("./icpc2014-dataset/G/"+fname+".out","r")
    all=f.readlines()
    f.close()
    cnt=0
    diff=0
    for l in all:
#        print ans[cnt],
#        print l
        if int(l)!=int(ans[cnt]):
            diff+=1
        cnt+=1
    print diff
