import sys
import argparse


def main():
    
    for _ in range(int(input())):
        ioarea = {}
        n = int(input())
        a = list(map(int,input().split()))
        for i in range(0,n):
            for j in range(i+1,n):
                ioarea[(a[j]-a[i])] = 1
        print(len(ioarea.keys()))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()