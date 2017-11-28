from TC_BST import *
class CNode():
	def __init__(self,ob=None,key=None,color=None,p=None,left=None,right=None):
		self.ob=ob;self.key=key;self.color=color;self.p=p;self.left=left;self.right=right;
	def Copy(self):
		return CNode(self.ob,self.key,self.color,self.p,self.left,self.right)
