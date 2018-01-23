from TC_Hash import *
from TC_Linkedlist import *
L0=[1,2,3,4,5,6,7,8,9,10]
Lt=[10,9,8,7,6,5,4,3,2,1]
L=[]
Maxd=len(L0)

def abs(i):
	if i<0:
		i=-i
	return i

def HashF(LL):
	n=len(LL)
	a=0
	for i in range(0,n):
		a+=LL[i]*pow(10,i)
	return a % 37547

class hashl:
	def __init__(self,ob,depth=0,parent=None):
		self.object=ob
		self.depth=depth
		self.parent=parent
		self.key=ob

def check(l,q):
	#top=1
	ans=100
	L1=l.object
	dn=l.depth
	#print "Start!!!!!",L1,dn
	if dn > 0:
		dn+=1
		srch=range(-Maxd/2-1,-1)
	else :
		srch=range(1,Maxd/2+1)
		dn-=1
	N=len(L1)
	NN=0
	okok=1
	for i in range(0,N):
		for j in range(i+1,N):
			for k in range(0,i-1):
				#print "Now is {}".format(NN)
				NN+=1
				Ln=L1[0:k]+L1[i:j]+L1[k:i]+L1[j:N]
				#OutputHash(L)
				wh=1
				#print Ln
				ln=hashl(Ln,dn,l)
				if Search(ln,L,HashF):
					wh=0
					lget=Get(ln,L,HashF)
					dd=lget.depth
					if dd*dn < 0:
						ans=abs(dn-dd)-2
						#print ln.object
						print "One Direction:"
						while not lget==None:
							print lget.object
							lget=lget.parent
						print "Another"
						while not ln==None:
							print ln.object
							ln=ln.parent
						#print Ln
						print "ANS is {} steps".format(ans)
						return [0,ans]
				if wh:
					#print "Depth is ",dn,Ln
					Hash(ln,L,HashF)
					q.push(ln)
			for k in range(j+1,N+1):

				#print "Now is {}".format(NN)
				NN+=1
				Ln=L1[0:i]+L1[j:k]+L1[i:j]+L1[k:N]
				#print i,j,k,Ln
				#OutputHash(L)
				wh=1
				#print Ln
				ln=hashl(Ln,dn,l)
				if Search(ln,L,HashF):
					wh=0
					lget=Get(ln,L,HashF)
					dd=lget.depth
					if dd*dn < 0:
						ans=abs(dn-dd)-2
						#print ln.object
						print "One Direction:"
						while not lget==None:
							print lget.object
							lget=lget.parent
						print "Another:"
						while not ln==None:
							print ln.object
							ln=ln.parent
						#print Ln
						print "ANS is {} steps".format(ans)
						return [0,ans]
				if wh:
					#print "Depth is ",dn,Ln
					Hash(ln,L,HashF)
					q.push(ln)
	return [okok,ans]

#main:
l0=hashl(L0,1)
lt=hashl(Lt,-1)
CreateSlots(L,37550)
Hash(l0,L,HashF)
Hash(lt,L,HashF)
q=Queue(l0)
q.push(lt)
ok=1
if (L0==Lt):
	print "ANS is 0 steps"
else:
	while ok :
		qt=q.get()
		Lans=check(qt,q)
		ok=Lans[0]
		q.pop()

#print Lans[1]
#check(l0,q)
#OutputHash(L)
