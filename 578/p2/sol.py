import sys
import argparse


def main():
    for _ in range(0,int(input())):
        n,m,k = list(map(int,input().split()))
        h = list(map(int,input().split()))
        ans = "YES"
        for i in range(0,n-1):
            if (h[i+1]-h[i]) > k: # next one is tall
                # we want to put more blocks to even the height
                replacer = 0
                if h[i+1] - k >= 0:
                    replacer = h[i+1] - k
                blocks = replacer - h[i]
                m -= blocks
                if m < 0:
                    ans = "NO"
            else:
                replacer = 0
                if h[i+1] - k >= 0:
                    replacer = h[i+1] - k
                blocks = h[i] - replacer
                m += blocks
        print(ans)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()