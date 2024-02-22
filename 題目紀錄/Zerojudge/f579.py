a,b=map(int,input().split())
n=int(input())
cnt=0
while n>0:
    n-=1
    t=list(map(int,input().split()))
    if t.count(a)>t.count(-a) and t.count(b)>t.count(-b):
        cnt+=1
print(cnt)