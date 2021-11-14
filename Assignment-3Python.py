# 1 ques
# n = int(input())
# m = int(input())
# matrix = []
# for i in range(n):
#     x = []
#     x = [int(ele) for ele in input().split()]
#     matrix.append(x)    
# transpose = []
# for i in range(m):
#     transpose.append([None]*n)
# for i in range(n):
#     for j in range(m):
#         transpose[j][i] = matrix[i][j]    

# print(matrix)    
# print(transpose)

# 2 ques
# n,m = (int(x) for x in input().split())
# matrix = [[int(x) for x in input().split()] for i in range(n)]
# a,b = (int(x) for x in input().split())
# sum = 0
# if a-1>=0 and b-1>=0:
#     sum += matrix[a-1][b-1]
# if a-1>=0:
#     sum += matrix[a-1][b]
# if a-1>=0 and b+1<m:
#     sum += matrix[a-1][b+1]
# if b-1>=0:
#     sum += matrix[a][b-1]
# if b+1<m:
#     sum += matrix[a][b+1] 
# if a+1<n and b-1>=0:
#     sum += matrix[a+1][b-1]
# if a+1<n:
#     sum += matrix[a+1][b]
# if a+1<n and b+1<m:
#     sum += matrix[a+1][b+1]
# print(sum)                       

# 3 ques
