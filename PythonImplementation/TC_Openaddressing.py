def HashF1(a):
	return a
def HashF2(a):
	return 1+a%10
def CreateSlots(L,m):
	for i in range(0,m):
		L.append(None)

def Hash(L,i):
	n=len(L)
	def g():
		for j in range(0,n):
			yield (HashF1(i)+j*HashF2(i))%n
	a=1
	for x in g():
		if L[x]==None:
			L[x]=i
			a=0
			break
	if a:
		print "Overflow!!!"
 

L=[]
L1=[10,22,31,4,15,28,17,88,59,1,2]
CreateSlots(L,11)
for item in L1:
	Hash(L,item)
print L
