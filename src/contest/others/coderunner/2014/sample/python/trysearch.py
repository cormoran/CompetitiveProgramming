import urllib2
import time
import random
def query(url):
	res = urllib2.urlopen(url)
	return res.read()

token = "CDO1V37RNSLDXXYPF37KIK4L7LCT43BP"


tls=[1,'A']
alist =[tls]


ans1200 ='DCCDAAABBBBBAADCBBCABDBBABADDBDADCCBBABDBCCBBBADAC'
maxans=1605
while 1:
        for j in range(0,50):
                for i in range(0,4):

                        ans1200k=ans1200[0:j]+chr(ord('A')+i)+ans1200[j+1:len(ans1200)]

                        url    = "https://game.coderunner.jp/q?str=%s&token=%s" % (ans1200k,token)
                        result = query(url)
                        print ans1200k
                        print result
                        if int(result)>=maxans:
                                ans1200=ans1200k
                                maxans=int(result)

                        time.sleep(1)
