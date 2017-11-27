import random
random.seed()

def partition(L,p,r,a):
	i=p-1
	t=L[r];L[r]=L[a];L[a]=t
	key = L[r]
	for j in range(p,r):
		if L[j]<=key:
			i += 1
			t=L[j];L[j]=L[i];L[i]=t
	i+=1;t=L[r];L[r]=L[i];L[i]=t
	return i

def randomized_partition(L,p,r):
	if(p==r) :
		return p
	a = random.randrange(p,r+1,1)
	#print L[a]
	t = partition(L,p,r,a)
	#print L
	return t

def randomized_select(L,p,r,i):
	#print "This is i"
	#print i
	if(i>r-p+1 or i<=0):
		print "Wrong!!!"
		return 
	if(p==r):
		return L[p]
	q = randomized_partition(L,p,r)
	k= q-p+1
	if(k==i):
		return L[q]
	if(k>i):
		return randomized_select(L,p,q-1,i)
	return randomized_select(L,q+1,r,i-k)

L=[9,3,4,1,5,2,8,10,6,7]
for x in range(0,11):
	print randomized_select(L,0,9,x)
print L
