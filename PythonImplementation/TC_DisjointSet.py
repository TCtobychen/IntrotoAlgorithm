class Node:
	def __init__(self,ob,parent=None):
		self.object=ob
		self.parent=parent

def Makeset(ob):
	t=Node(ob)
	t.parent=t
	return t
def Findset(node):
	while not node.parent==node:
		node.parent=Findset(node.parent)
	return node.parent
a=5
Makeset(a)
print Findset(a)
