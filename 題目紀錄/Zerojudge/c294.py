a=list(map(int,input().split()))
a.sort()
print(a[0],a[1],a[2])
if a[0]+a[1]<=a[2]:
    print("No")
elif a[0]**2+a[1]**2<a[2]**2:
    print("Obtuse")
elif a[0]**2+a[1]**2==a[2]**2:
    print("Right")
else:
    print("Acute")