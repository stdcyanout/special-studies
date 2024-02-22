import sys
import math
while True:
    try:
        a,b,c=map(int,sys.stdin.readline().strip().split())
        s=(a+b+c)/2
        print(math.sqrt(s*(s-a)*(s-b)*(s-c)))
    except EOFError:
        break