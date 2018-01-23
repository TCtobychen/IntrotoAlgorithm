from TC_Linkedlist import *

'''
Usage:
Okay, I finally realize that I should write a readme for this python file because it's frequent to 
be imported and even myself often forget how to use. So...:

Oh! I find that I have a sample at the end of the file. so... just check that. 

'''
def CreateSlots(L,n):
	for i in range(0,n):
		L.append(newnode())
def hf(LL): # You should write your own hash function here
	return LL%10

def Hash(objt,L,hashfunction=hf): #Input HashObj
	h=hashfunction(objt.key)
	T=Node(objt)
	T.nex=L[h]
	L[h].prev=T
	L[h]=T
	return T
def OutputHash(L):
	for i in range(0,len(L)):
		t=L[i]
		if not t.object==None:
			print "\n"
			print i,
			print "Start"
		while not t.object==None:
			print t.object.object
			t=t.nex
	print "END"
	print "\n"
def OutputNodes(L):
	for item in L:
		print item.prev
def Search(ob,L,hashfunction=hf):
	a=L[hashfunction(ob.key)]					
	if a.object == None:
		return 0
	if a.object.object==ob.object:
		return 1
	while not a.object.object==ob.object:
		#print a.object.object
		if a.nex==None:
			return 0
		if a.nex.object==None:
			return 0
		else :
			a=a.nex
	return 1
def Get(ob,L,hashfunction=hf):
	a=L[hashfunction(ob.key)]					
	if a.object == None:
		return None
	if a.object.object==ob.object:
		return a.object
	while not a.object.object==ob.object:
		#print a.object.object
		if a.nex==None:
			return None
		if a.nex.object==None:
			return None
		else :
			a=a.nex
	return a.object
'''L=[]
L1=[5,28,19,15,20,33,12,17,10]
L2=[5,28,19,15,20,33,12,17,10]
TurntoHash(L1,L2)
CreateSlots(L,9)
for i in range(0,len(L1)):
	L1[i]=Hash(L1[i],L)
print Search(7,1,L)
OutputHash(L)
OutputNodes(L1)'''
'''L=[]
class num:
	def __init__(self,num):
		self.object=num
		self.key=num'''
'''CreateSlots(L,9)
Hash(num(4),L);Hash(num(5),L);Hash(num(14),L)
print OutputHash(L)
print Search(num(4),L)'''
