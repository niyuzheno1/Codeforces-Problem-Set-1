import sys
import argparse

def inrange(x, y ,z):
    return min(y,z) <= x and x <= max(y,z)


def main():
    for _ in range(int(input())):
        n = int(input())
        a = []
        for i in range(0, n):
            b = list(map(int,input().split()))
            a.append(b)
        a.append([50*a[n-1][0], 0])
        n = n +1
        pcx = 0
        cx = 0
        mx = 0
        tx = 0
        t = 0
        success = 0
        for i in range(0, n):
            pcx = cx
            ct = min(abs(tx-cx), a[i][0] - t) 
            cx = cx + min(abs(tx-cx), a[i][0] - t) * mx
            if tx == cx:
                if i != 0:
                    if inrange(a[i-1][1], min(pcx,cx), max(pcx,cx)):
                        success = success + 1
                if a[i][1] - cx > 0:
                    mx = 1
                elif a[i][1] - cx < 0:
                    mx = -1
                else:
                    mx = 0 
                t = a[i][0]
                tx = a[i][1]
            else:
                if inrange(a[i-1][1], min(pcx,cx), max(pcx,cx)) :
                    success = success + 1
                t = a[i][0]

        print(success)
                

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()