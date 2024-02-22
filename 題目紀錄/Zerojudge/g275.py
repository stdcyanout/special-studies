s=["None","A","B","AB","C","AC","BC","ABC"]
n=int(input())
while n>0:
    n-=1
    ind=0
    a=list(map(int,input().split()))+list(map(int,input().split()))
    if a[1]==a[3] or a[1]!=a[5] or a[8]==a[10] or a[8]!=a[12]:
        ind+=1
    if a[6]==0 or a[13]==1:
        ind+=2
    if a[1]==a[8] or a[3]==a[10] or a[5]==a[12]:
        ind+=4
    print(s[ind])