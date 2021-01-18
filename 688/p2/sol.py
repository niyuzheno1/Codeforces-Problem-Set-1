import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        sum = [0] * n
        diff = [0] * n
        delta = 0
        goal = a[0]
        for i in range(1,n):
            numop = abs(delta + a[i] - goal)
            sum[i] = numop 
            delta +=  goal-(a[i]+delta)
        s = 0
        for i in range(0,n):
            s += sum[i]
        for i in range(0,n-1):
            l = 0 if i == 0 else a[i-1]
            r = a[i+1]
            diff[i] = abs(l-r)
        diff[0] = 0
        ans = None
        for i in range(0,n):
            sx = sum[i+1] if i+1 < n else 0
            ansx = s - (sum[i] + sx) +diff[i]
            if ans is None or ans > ansx:
                ans = ansx
        print(ans)
        

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()