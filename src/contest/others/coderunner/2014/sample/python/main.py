import urllib2
import time

def query(url):
	res = urllib2.urlopen(url)
	return res.read()

token = "xxxxxxx"

for i in range(0, 2):
	url    = "http://example.com/api01?token=%s" % token
	result = query(url)
	print result

	time.sleep(1)