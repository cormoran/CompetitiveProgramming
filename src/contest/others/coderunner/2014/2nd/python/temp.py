import urllib2
import time

def query(url):
	res = urllib2.urlopen(url)
	return res.read()

token = "CDO1V37RNSLDXXYPF37KIK4L7LCT43BP"

def get_info():
        url    = "https://game.coderunner.jp/info?token=%s&filter=%s&style=%s" % (token,"history","text")
        result = query(url)
        lst=result.split('\r\n')
        maxattack=80
        max=0
        print result
        for i in range(0,len(lst)-1):
             item=lst[i].split(' ')
             if len(item)==3:
                     if max < int(item[2]):
                             max=int(item[2])
                             maxattack=int(item[1])
        return maxattack

while 1:
        attack=get_info()
        url='https://game.coderunner.jp/attack?token=%s&skill=%d'%(token,attack)
        result=query(url)
        print str(attack)+" "+result
	time.sleep(1)
