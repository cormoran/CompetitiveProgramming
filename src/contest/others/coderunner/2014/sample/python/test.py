import urllib2
import time
import random
def query(url):
	res = urllib2.urlopen(url)
	return res.read()

token = "CDO1V37RNSLDXXYPF37KIK4L7LCT43BP"
random.seed()

while 1:
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
	print result

	time.sleep(1)
