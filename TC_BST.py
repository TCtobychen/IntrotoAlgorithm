import TC_TreeNode as tree 
from TC_Linkedlist import *

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
				t.p.left==None
			else:
				t.p.right==None
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
				t.p.left==None
			else:
				t.p.right==None
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

# Test Cases:
L=[5,3,6,8,2,4,10,1,7,9]
R=tree.Node(L[0],L[0])
for i in range(1,10):
	Insert(R,L[i],L[i])
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


