import sys
sys.setrecursionlimit(50005)
n=int(sys.stdin.readline().strip())
s=list(map(int,sys.stdin.readline().strip().split()))
vis=[0]*n
cnt=0
for i in range(n):
    if vis[i]==1:
        continue
    cnt+=1
    tmp=i
    while vis[tmp]==0:
        vis[tmp]=1
        tmp=s[tmp]
print(cnt)