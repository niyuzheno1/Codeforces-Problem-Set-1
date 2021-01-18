import sys
import argparse


def main():
    n = int(input())
    a = list(map(int,input().split()))
    inverse = 0
    for i in range(0,n):
        for j in range(i,n):
            if a[i] > a[j]:
                inverse = inverse + 1
    print(inverse)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()