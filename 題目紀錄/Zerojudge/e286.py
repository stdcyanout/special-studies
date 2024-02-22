a=sum(list(map(int,input().split())))
b=sum(list(map(int,input().split())))
c=sum(list(map(int,input().split())))
d=sum(list(map(int,input().split())))
print(a,b,sep=':')
print(c,d,sep=':')
host=0
guest=0
if a>b:
    host+=1
else:
    guest+=1
if c>d:
    host+=1
else:
    guest+=1
if host>guest:
    print("Win")
elif host==guest:
    print("Tie")
else:
    print("Lose")