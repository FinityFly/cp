# n=int(input())
# p=[1 for _ in range(n+1)]
# i=2
# for i in range(2,int(n**0.5)+1):
#     if p[i]:
#         for j in range(i*i,n+1,i):
#             p[j]=0
# p[0]=0
# for i in range(2,n+1):
#     if p[i]:
#         if p[i-2] or p[i+2]:
#             print(str(i)+'*')
#         else:
#             print(i)

# 56/100
# [p:=[0]+[1]*((n:=int(input()))+2)],[p.__setitem__(j,0)for i in range(2,int(n**0.5)+2)if p[i]for j in range(i*i,n+1,i)],print('\n'.join((str(i)+('*'if(p[i-2]|p[i+2])else''))for i in range(2,n+1)if p[i]))

# 60/100
# [p:=[0]+[1]*(n:=int(input()))],[p.__setitem__(j,0)for i in range(2,int(n**.6))if p[i]for j in range(i*i,n+1,i)],print('\n'.join(str(i)+('*'if p[i-2]|p[i+2]else'')for i in range(2,n+1)if p[i]))

# 62/100
# [p:=[0]+[1]*(n:=int(input()))],[p.__setitem__(j,0)for i in range(2,int(n**.6))if p[i]for j in range(i*i,n+1,i)],print('\n'.join(f"{i}{'*'*(p[i-2]|p[i+2])}"for i in range(2,n+1)if p[i]))

# 68/100
# [p:=[0,0]+[1]*(n:=int(input())+1)],[p.__setitem__(j,0)for i in range(n)if p[i]for j in range(i*i,n,i)],print('\n'.join(f"{i}{'*'*(p[i-2]|p[i+2])}"for i in range(n)if p[i]))

# first change format of prime list to store prime value instead of bool
# use one for loop for both setting non primes 0 and printing
# 91/100
# [p:=[*range(int(input()))],[[*[p.__setitem__(j,0)for j in p[i*i::i]],print(str(i)+'*'*(1&(p[i-2]|p[i+2])))]for i in p[2:]if p[i]]]
# [p:=[*range(int(input()))]],[[*[p.__setitem__(j,0)for j in p[i*i::i]],print(str(i)+'*'*(1&(p[i-2]|p[i+2])))]for i in p[2:]if p[i]]
[B:=[*range(int(input()))]],[[*[B.__setitem__(A,0)for A in B[A*A::A]],print(str(A)+'*'*(1&(B[A-2]|B[A+2])))]for A in B[2:]if B[A]]

# illegal/100
# exec(bytes('灛㴺⩛慲杮⡥湩⡴湩異⡴⤩崩ⱝ孛嬪⹰彟敳楴整彭⡟ⱪ⤰潦⁲⁪湩瀠楛椪㨺嵩ⱝ牰湩⡴瑳⡲⥩✫✪⠪☱瀨楛㈭籝孰⭩崲⤩崩潦⁲⁩湩瀠㉛崺晩瀠楛嵝','u16')[2:])

# more optimizations might be possible with more list comprehensions