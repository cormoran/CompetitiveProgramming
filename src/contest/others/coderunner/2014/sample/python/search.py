import urllib2
import time
import random
def query(url):
	res = urllib2.urlopen(url)
	return res.read()

token = "CDO1V37RNSLDXXYPF37KIK4L7LCT43BP"


tls=[1,'A']
alist =[tls]

while 1:
        for a in range(0,50):
                random.seed()
                ans=''
                for j in range(0,50):
                        k=random.randint(0,3)
                        if k==0:
                                ans+='A'
                        if k==1:
                                ans+='B'
                        if k==2:
                                ans+='C'
                        if k==3:
                                ans+='D'

                print ans
                url    = "https://game.coderunner.jp/q?str=%s&token=%s" % (ans,token)
                result = query(url)
                resint=int(result)
                if resint>800:
                        temp=[int(result),ans]
                        alist+=temp
                print result
                if len(alist)>100:
                        f=open("./ans","a")
                        try:
                                for b in range(0,len(alist)):
                                        f.write(a[b])
                                        f.write('\n')
                        finally:
                                f.close()
                time.sleep(1)
