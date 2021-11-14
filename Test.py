import math
T = int(input())
for i in range(T):
	n = int(input())
	sum = 2*n
	x = math.log(n,2)
	x = int(x)
	# x = math.ceil(x)
	p = math.pow(2,x)
	sum = sum*(p-1)
	sum = sum/p
	print(int(sum))
	