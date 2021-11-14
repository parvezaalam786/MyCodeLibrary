N = int(input())
arr = [int(x) for x in input().split()]
arr.sort()
prod = 1
for i in arr:
	prod *= i
	if prod>10**18:
		prod = -1
		break
print(prod)