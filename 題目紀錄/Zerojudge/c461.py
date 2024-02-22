arr = list(map(int, input().split()))
a=True
b=True
c=True
impossible=True
if arr[0]==0:
    a=False
if arr[1]==0:
    b=False
if arr[2]==0:
    c=False

if (a and b) == c:
    print("AND")
    impossible=False
if (a or b) == c:
    print("OR")
    impossible=False
if ((a or b) and (not (a and b))) == c:
    print("XOR")
    impossible=False
if impossible:
    print("IMPOSSIBLE")