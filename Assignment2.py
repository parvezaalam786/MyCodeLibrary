# 1 ques
# nums = [int(x) for x in input().split(",")]
# sum = 0
# for i in nums:
#     sum += i
# if sum>100:
#     print("0")
# else:
#     print(sum)

# 2 ques
# s1, s2 = (x for x in input().split(","))
# s3 = 2*s1+5*s2
# print(s3)

# 3 ques
# n = int(input())
# a = n//2
# b = 0
# s1 = '* '
# s2 = '  '
# for i in range(n):
#     print(s1*a+b*s2+s1*a)
#     a -= 1
#     b += 2 

# 4 ques
# n = int(input("Enter a number: "))
# odd = 0
# even = 1
# turn = True
# while n != 0:
#     a = n%10
#     if turn:
#         even *= a
#         turn = False
#     else:
#         odd += a
#         turn = True
#     n = n//10    
# if even % odd == 0:
#     print("Yes")
# else:
#     print("No")                

# 5 ques
# n = int(input())
# N = 2*n-1
# for i in range(N):

# 6 ques
# l1 = [int(x) for x in input().split()]
# print(l1)
# l1.reverse()
# print(l1)

# 7 ques
# x = [int(x) for x in input().split()]
# m1 = {}
# for i in x:
#     if i in m1:
#         m1[i] += 1
#     else:
#         m1[i] = 1
# ans = []
# for i in m1:
#     if m1[i]>1:
#         ans.append(i)
# print(ans)

# 8 ques
# arr = [int(x) for x in input("Enter the array:").split()]
# n = len(arr)
# sum = int(input("input the sum"))
# found = False
# cursum = 0
# a = 0
# b = 0
# for i in range(n):
#     cursum = arr[i]
#     for j in range(i+1,n):
#         if cursum == sum:
#             found = True
#             a = i
#             b = j-1
#         if cursum>sum:
#             break
#         cursum += arr[j]    
# if found:
#     print("Subarray found:")
#     for i in range(a,b+1):
#         print(arr[i],end=" ")
# else:
#     print("Subarray not exists")

# 9 ques
# l1 = [int(x) for x in input("Enter the array1:").split()]
# l2 = [int(x) for x in input("Enter the array2:").split()]
# l1.extend(l2)
# x = 0
# for i in l1:
#     y = i
#     x = x^y
# print(x)    

# 10 ques
# s1 = input()
# l = len(s1)
# sum = 0
# for i in range(l):
#     s = str(s1[i])
#     if s.isdigit():  
#         sum += int(s1[i])
# print(sum)         

# 11 ques
# s1 = input()
# s2 = ""
# l = len(s1)
# for i in range(l-1,-1,-1):
#     s2 = s2+s1[i]
# # print(s2)    
# if s1==s2:
#     print("Yes palindrome")
# else:
#     print("Not palindrome")    

# 12 ques
# s1 = input()
# s1 = list(s1)
# s2 = s1[::-1]
# s2 = str(s2)
# s1 = str(s1)
# if s1==s2:
#     print("Yes palindrome")
# else:
#     print("Not palindrome")  

# 13 ques
# s1 = input()
# a = s1[0]
# s1 = s1.replace(s1[0],"#")
# s1 = a+s1[1:]
# print(s1)

# 14 ques
# s = input()
# digits = 0
# alph = 0
# for i in range(len(s)):
#     s1 = str(s[i])
#     if s1.isdigit():
#         digits += 1
#     else:
#         alph += 1
# print("digits=",digits,"alphabets=",alph)            

