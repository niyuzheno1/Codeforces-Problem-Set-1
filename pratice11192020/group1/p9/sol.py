import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        l = list(map(int,input().split()))
        b = []
        for i in range(0,n):
            if l[i] == 0:
                b.append(a[i])
        b.sort(reverse=True)
        for i in range(0,n):
            if l[i] == 0:
                x = b.pop(0)
                a[i] = x
        print(" ".join(list(map(str,a))))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()