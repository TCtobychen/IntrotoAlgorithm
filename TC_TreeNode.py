class Node():
	def __init__(self,ob=None,key=None,p=None,left=None,right=None):
		self.ob=ob;self.key=key;self.p=p;self.left=left;self.right=right;
	def Copy(self):
		return Node(self.ob,self.key,self.p,self.left,self.right)
