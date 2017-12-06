L=[3,2,1,0]
def BFind(B,A,i,j): # Use binary search to find the largest m such that B[m]<=A
	if j<=i:
		print "Error!!"
		return 
	if j == i+1:
		return i
	k=int((i+j)/2)
	if B[k] <= A:
		return BFind(B,A,k,j)
	if B[k] > A:
		return BFind(B,A,i,k)

def LMInc(L):
	M=1
	B=[100000000];C=[[0]]
	N=len(L)
	for i in range(0,N):
		A=L[i]
		if A < B[0]:
			B[0]=A
			C[0][0]=A
		else :
			j=BFind(B,A,0,len(B))
			if j==M-1:
				M=M+1
				B.append(A)
				C.append([])
				for k in range(0,j+1):
					C[M-1].append(C[M-2][k])
				C[M-1].append(A)
			else :
				for k in range(0,j+1):
					C[j+1][k]=C[j][k]
					C[j+1][j+1]=A
					B[j+1]=A
	print C[M-1]
LMInc(L)

