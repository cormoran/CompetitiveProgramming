try:
	while 1: d=list(map(int,input().split()));print(['Fail','Pass'][sum(d)/d[0]-1<d[1]*2])
except:0
