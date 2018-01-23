# Liurujia Purple P 206
from TC_Gcd import gcd
A,B=19,45
ans=[]
tmp=[]
for i in range(0,100):
	ans.append(100000)
for i in range(0,100):
	tmp.append(100000)
def find(a,b):
	f=float(a)/b
	c=int(1/f)
	if float(1/c)>f:
		c+=1
	return c

def upbound(i,a,b,maxd):
	return int(b*(maxd-i)/a)

def copy(L1,L2):
	for i in range(0,len(L1)):
		L2[i]=L1[i]

def minus(a,b,i):
	nu=a*i-b
	nd=b*i
	#print nu,nd
	if nu==0:
		return [0,1]
	#print nu,nd
	d=gcd(nu,nd)
	nu=nu/d
	nd=nd/d
	return [nu,nd]
def dfs(n,c,a,b,maxd):
	ANS=0
	if a==0:
		#print "HAHAHA"
		if tmp[maxd-1]<ans[maxd-1]:
			copy(tmp,ans)
		return 1
	if n==maxd:
		return 
	else :
		#print a,b,n
		for i in range(max(c,find(a,b)),upbound(n,a,b,maxd)+1):
			if float(a)/float(b) < 1/float(i) :
				continue
			L=minus(a,b,i)
			#print "nis{}".format(n)
			tmp[n]=i
			#print "Now{}".format(i),
			print i,L
			temp=dfs(n+1,i,L[0],L[1],maxd)
			if temp:
				ANS=1
			tmp[n]=100000
	return ANS



def Egyptian(a,b):
	maxd=1
	ok=0
	while not ok:
		print "Round{}".format(maxd)
		ok=dfs(0,0,a,b,maxd)
		for i in range(0,maxd-1):
			#print "ANS:"
			print ans[i]
		maxd+=1
	print "ANS"
	for i in range(0,maxd-1):
		#print "ANS:"
		print ans[i]

Egyptian(A,B)