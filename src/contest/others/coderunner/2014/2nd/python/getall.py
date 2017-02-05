import urllib2
import time
import random

def query(url):
	res = urllib2.urlopen(url)
	return res.read()

token = "CDO1V37RNSLDXXYPF37KIK4L7LCT43BP"


def throw_rand():
        url='https://game.coderunner.jp/attack?token=%s&skill=%d'%(token,random.randint(0,99))
        result=query(url)
        print result

def get_info():
        url    = "https://game.coderunner.jp/info?token=%s&filter=%s&style=%s" % (token,"all","text")
        result = query(url)
        alst=result.split('\r\n')
        lst=alst[6:]
        maxattack=80
        max=0
        flg=0
        ids=0;
        for i in range(0,len(lst)-1):
             if len(lst[i].split(' '))==3:
                     item=map(int,lst[i].split(' '))
                     if ids!=item[0]:
                             flg+=1
                             ids=item[0]
                     if max < item[2]:
                             max=item[2]
                             maxattack=item[1]
        if flg==1 and max<500:
             maxattack=random.randint(0,99)   
        return maxattack
random.seed()
while 1:
        attack=get_info()
        url='https://game.coderunner.jp/attack?token=%s&skill=%d'%(token,attack)
        result=query(url)
        print str(attack)+" "+result
	time.sleep(1)
