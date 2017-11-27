def printprimes():
	def dlt(L,i):
		t=2
		while t:
			if(i*t<len(L)):
				L[i*t]=0
			else :
				return 
			t+=1
	L=[]
	i=0
	while i < 1000000000000000000:
		L.append(i)
		i+=1
	for i in range(2,(len(L)+1)/2+1):
		if L[i]:
			dlt(L,i)

	for i in range(2,len(L)-1):
		if L[i]:
			print i

def isprime(n):
	t=(int)(n**0.5)+1
	for i in range(2,t):
		if n%i == 0:
			return 
	print n

a=2
while a<1000000000000000:
	isprime(a)
	a+=1