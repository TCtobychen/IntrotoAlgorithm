'''print "Please Enter two rows, splited by spaces"
L1=raw_input("First row:").split(' ')
L2=raw_input("Second row:").split(' ')
print L1,L2'''
L1=[2,4,5,6]
L2=[2,4,5,6]
N1=len(L1)
N2=len(L2)

def CreateListof(n,ob=None):
	L=[]
	for i in range(0,n):
		L.append(ob)
	return L
def CreateDArrays(n1,n2):
	L=[]
	for i in range(0,n1):
		L.append(CreateListof(n2))
	return L
def lsc_tb(L1,L2,a,b,L): # It does the job by filling the needed L table recursively. 
	if a==-1 or b==-1:
		return 0
	if not L[a][b]==None:
		return L[a][b]
	if L1[a]==L2[b]:
		L[a][b]=lsc_tb(L1,L2,a-1,b-1,L)+1
		return L[a][b]
	L[a][b] = max(lsc_tb(L1,L2,a,b-1,L),lsc_tb(L1,L2,a-1,b,L))
	return L[a][b]

def lsc_bt(L1,L2): # It does the job by bottom-up calculating to the need depth. 
	L=CreateListof(len(L1)+1,0)
	for i in range(1,len(L2)+1):
		t=0
		for j in range(1,len(L1)+1):
			if L2[i-1]==L1[j-1]:
				s=L[j-1]+1
				L[j-1]=t
				t=s
			else:
				s=max(t,L[j])
				L[j-1]=t
				t=s
		L[len(L1)]=t
	return t

L=CreateDArrays(N1+1,N2+1)
print lsc_tb(L1,L2,N1-1,N2-1,L)
print lsc_bt(L1,L2)