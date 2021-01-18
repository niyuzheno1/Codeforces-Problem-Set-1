import sys
import argparse


def main():
    for _ in(range(int(input()))):
        nxy = list(map(int,input().split()))
        n,x,y = nxy
        ans = None
        rdelta = None
        lfirst = None
        pos = None
        for i in range(1,n+1):
            for j in range(i+1, n + 1):
                if (y-x)%(j-i) != 0:
                    continue
                delta = (y-x)/(j-i)
                firstelement = x-(i-1) * delta
                if firstelement <= 0:
                    continue
                maxn = x + (n-i)*delta
                if ans is None:
                    ans  = maxn
                    lfirst = firstelement
                    rdelta = delta
                    pos = (i,j)
                else:
                    ans = min(ans,maxn)
                    if ans == maxn:
                        lfirst = firstelement
                        rdelta = delta
                        pos = (i,j)
        arr = []
        for i in range(1,n+1):
            arr.append(int(lfirst + rdelta *(i-1)))
        arr = list(map(str,arr))
        print(" ".join(arr))
        

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()