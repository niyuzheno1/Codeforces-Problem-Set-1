import sys
import argparse

def getsum(x, y, d):
    sum = 0
    cnt = 0
    u = x
    while x%y==0 and cnt <= d:
        cnt = cnt + 1
        sum += u
        x /= y
    return (sum,cnt)
        

def main():
    for _ in range(int(input())):
        n,x = list(map(int,input().split()))
        a = list(map(int,input().split()))
        b = [None]*n
        for i in range(0,n):
            b[i] = getsum(a[i],x,a[i])
        u = b[0][1]
        idx = 0
        for i in range(0,n):
            if(u > b[i][1]):
                idx = i
                u = b[i][1]
        ans = 0
        for i in range(0,n):
            ux = 0
            if i > idx:
                ux = getsum(a[i], x, u-1)[0]+a[i]
            else:
                ux = getsum(a[i], x, u)[0]+a[i]
            ans += ux
        print(ans)
        

        

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()