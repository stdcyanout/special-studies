import sys
def getline():
    return sys.stdin.readline().strip()
def getlines():
    return sys.stdin.readlines()

def main():
    while True:
        try:
            year=int(getline())
            if ((year%4==0) and (year%100!=0)) or (year%400==0):
                print("閏年")
            else:
                print("平年")
        except:
            return

if __name__=="__main__":
    main()