#L=raw_input("Please Enter the rows & columns of your matrices here:\n(Note:Use comma to split)\n").split(',')
L=[30,35,15,5,10,20,25]
N=len(L)-1  # There are N matrices all together. 
def CreateListofn(n):
	L=[]
	for i in range(0,n):
		L.append(0)
	return L
def CreateMatrixofn(n):
	m=[]
	for j in range(0,n):
		m.append(CreateListofn(n))
	return m
m=CreateMatrixofn(N)
for l in range(1,N):
	for i in range(0,N-l):
		j=i+l
		m[i][j]=100000000
		for k in range(i,j):
			q=m[i][k]+m[k+1][j]+L[i]*L[k+1]*L[j+1]
			if q < m[i][j]:
				m[i][j]=q
print m
