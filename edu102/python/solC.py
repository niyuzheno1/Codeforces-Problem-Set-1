import sys
import argparse


def main():
    for _ in range(int(input())):
        n, k = list(map(int,input().split()))
        u = 1
        a = []
        for i in range(0, k-(n-k+1)):
            a.append(u)
            u = u + 1
        u = k
        for i in range(0, n-k+1):
            a.append(u)
            u = u -1
        print(" ".join(list(map(str,a))))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()