def calc(a,b,c,x):
    return a*x*x+b*x+c

a1,b1,c1=map(int,input().split())
a2,b2,c2=map(int,input().split())
maxearn=-2147483648
n=int(input())
for i in range(0,n+1):
    maxearn=max(maxearn,calc(a1,b1,c1,i)+calc(a2,b2,c2,n-i))
print(maxearn)