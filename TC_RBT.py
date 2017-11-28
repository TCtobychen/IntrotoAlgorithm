import TC_BST as bst
class CNode():
	def __init__(self,ob=None,key=None,color=None,p=None,left=None,right=None):
		self.ob=ob;self.key=key;self.color=color;self.p=p;self.left=left;self.right=right;
	def Copy(self):
		return CNode(self.ob,self.key,self.color,self.p,self.left,self.right)

def Insert(root,ob,key):
	t=root
	while not t==None:
		s=t
		if key < t.key:
			t=t.left
		else :
			t=t.right
	if key < s.key:
		a=CNode(ob,key,'r',s)
		s.left=a
	else :
		a=CNode(ob,key,'r',s)
		s.right=a
	
