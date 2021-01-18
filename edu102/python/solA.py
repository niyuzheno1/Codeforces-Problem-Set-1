import sys
import argparse


def main():
    for _ in range(int(input())):
        n, m = list(map(int,input().split()))
        a = list(map(int,input().split()))
        flag = True
        for i in range(0, n):
            if a[i] > m:
                flag = False
        if flag:
            print("YES")
            continue
        a = sorted(a)
        if n != 1:
            if a[0] + a[1] <= m:
                print("YES")
                continue
        print("NO")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()