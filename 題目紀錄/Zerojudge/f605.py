n,d=map(int,input().split())
cnt=0
cost=0
while n>0:
    n-=1
    a,b,c=map(int,input().split())
    if max(a,b,c)-min(a,b,c)>=d:
        cnt+=1
        cost+=(a+b+c)//3
print(cnt,cost)