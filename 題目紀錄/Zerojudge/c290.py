n=input()[::-1]
ans=0
cnt=0
for tmp in n:
    cnt+=1
    if cnt%2:
        ans+=int(tmp)
    else:
        ans-=int(tmp)
print(abs(ans))
