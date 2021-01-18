import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        if a[0] + a[1] <= a[n-1]:
            print("1 2 {}".format(n))
        else:
            print("-1")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()