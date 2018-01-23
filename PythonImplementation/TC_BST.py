import TC_TreeNode as tree 
from TC_Linkedlist import *

def Attach(x,y,i): # Attach x to y. i=1 for right, i=0 for left
	if not x.p==None:
		if x.p.left==x:
			x.p.left=None
		else :
			x.p.right=None
	x.p=y
	if i :
		if not y.right ==None:
			print "y has a right sub-tree, please CHECK!"
			return 
		y.right=x
	else:
		if not y.left==None:
			print "y has a left sub-tree, please CHECK!"
			return 
		y.left=x
def Insert(root,ob,key):
	t=root
	while not t==None:
		s=t
		if key < t.key:
			t=t.left
		else :
			t=t.right
	if key < s.key:
		a=tree.Node(ob,key,s)
		s.left=a
	else :
		a=tree.Node(ob,key,s)
		s.right=a
def Search(root,key):
	t=root
	while not t == None:
		if t.key == key:
			return True
		if key < t.key:
			t=t.left
		if key > t.key:
			t=t.right
	return False
def Find(root,key):
	t=root
	while not t == None:
		if t.key == key:
			return t
		if key < t.key:
			t=t.left
		if key > t.key:
			t=t.right
	print "Can't Find!"
def FindMin(root):
	t=root
	while not t.left==None:
		t=t.left
	return t
def FindMax(root):
	t=root
	while not t.right ==None:
		t=t.right
	return t
def Delete(root,key):
	t=Find(root,key)
	if t.left==None :
		if t.right == None:
			if t.p.left==t:
				t.p.left=None
			else:
				t.p.right=None
		else :
			t.right.p=t.p
			if t.p.left==t:
				t.p.left=t.right
			else:
				t.p.right=t.right
		t.right=None;t.ob=None;t.key=None
		return 
	if t.right==None :
		if t.left == None:
			if t.p.left==t:
				t.p.left=None
			else:
				t.p.right=None
		else :
			t.left.p=t.p
			if t.p.left==t:
				t.p.left=t.right
			else:
				t.p.right=t.right
		t.left=None;t.ob=None;t.key=None
		return
	z=t.right
	y=FindMin(z)
	if z == y:
		y.left=t.left;t.left.p=y;y.p=t.p;
		if t.p.left==t:
			t.p.left=y
		else : 
			t.p.right=y
		return 
	else:
		m=y.Copy()
		m.left=t.left;m.right=z;m.p=t.p;t.left.p=m;t.right.p=m;
		if t.p.left==t:
			t.p.left=m
		else : 
			t.p.right=m
		Delete(m.right,y.key)

def L_Rot(root,key):
	x=Find(root,key)
	y=x.right
	x.right=None;y.p=None
	if not y.left==None:
		Attach(y.left,x,1)
	if root==x:
		Attach(x,y,0)
		return y
	else:
		u=x.p
		if u.left==x:
			Attach(x,y,0)
			Attach(y,u,0)
		else:
			Attach(x,y,0)
			Attach(y,u,1)
		return root
def R_Rot(root,key):
	y=Find(root,key)
	x=y.left
	y.left=None;x.p=None
	if not x.right==None:
		Attach(x.right,y,0)
	if root==y:
		Attach(y,x,1)
		return x
	else:
		u=y.p
		if u.left==y:
			Attach(y,x,1)
			Attach(x,u,0)
		else:
			Attach(y,x,1)
			Attach(x,u,1)
		return root
def OutTree(R):
	q=Queue(R)
	a=q.get()
	while not a==None:
		print a.ob
		q.pop()
		if not a.left == None:
			q.push(a.left)
		if not a.right == None:
			q.push(a.right)
		a=q.get()

# Test Cases:
L=[5,3,6,8,2,4,10,1,7,9]
R=tree.Node(L[0],L[0])
for i in range(1,10):
	Insert(R,L[i],L[i])
R=L_Rot(R,8)
OutTree(R)



