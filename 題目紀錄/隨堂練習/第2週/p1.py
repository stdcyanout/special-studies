import sys
import math
def getline():
    return sys.stdin.readline().strip()
def getlines():
    return sys.stdin.readlines()

def main():
    while True:
        try:
            a,b,c=map(int,getline().split())
            if b**2-4*a*c<0:
                print("No real root")
                continue
            x1=(-b+math.sqrt(b**2-4*a*c))//(2*a)
            x2=(-b-math.sqrt(b**2-4*a*c))//(2*a)
            if x1>x2:
                print("Two different roots x1=%d , x2=%d"%(x1,x2))
            elif x1==x2:
                print("Two same roots x=%d"%(x1))
            else:
                print("Two different roots x1=%d , x2=%d"%(x2,x1))
        except:
            return

if __name__=="__main__":
    main()