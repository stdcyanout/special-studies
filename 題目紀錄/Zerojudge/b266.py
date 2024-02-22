import sys
s=sys.stdin.readlines()
r,c,m=map(int,s[0].strip().split())
op=list(map(int,s[r+1].strip().split()))[::-1]
init=[[0]*10 for x in range(10)]
tmp=[[0]*10 for x in range(10)]
for i in range(r):
    t=list(map(int,s[i+1].strip().split()))
    for j in range(c):
        init[i][j]=t[j]
for t in op:
    if t==0:
        for i in range(c):
            for j in range(r):
                tmp[i][j]=init[j][c-i-1]
        r,c=c,r
        for i in range(r):
            for j in range(c):
                init[i][j]=tmp[i][j]
    if t==1:
        for i in range(r//2):
            init[i],init[r-i-1]=init[r-i-1],init[i]
print(r,c)
for i in range(r):
    for j in range(c):
        print(init[i][j],end=' ')
    print()
        