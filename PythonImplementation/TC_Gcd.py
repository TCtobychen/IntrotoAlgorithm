def gcd(x,y):
	if x < y:
		return gcd(y,x)
	if x%y==0:
		return y
	else :
		return gcd(x-y*int(x/y),y)

#print gcd(4,2) 