import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        x = list(map(int,input().split()))
        a = [0] * n
        set_info = {}
        for i in range(0,n):
            if x[i] not in set_info:
                a[i] = x[i]
            else:
                a[i] = x[i]+1
            set_info[a[i]] = 1

        diversity = 0
        tmp = 0
        a = sorted(a)
        for i in range(0,n-1):
            if a[i] != a[i+1]:
                tmp = tmp + 1
        diversity = max(diversity, tmp)
        
        print(diversity+1)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()