import sys
import argparse


def main():
    for _ in range(int(input())):
        n,k = list(map(int, input().split()))
        ans = []
        for i in range(0,n):
            if i % 3 == 0:
                ans.append('a')
            if i % 3 == 1:
                ans.append('b')
            if i % 3 == 2:
                ans.append('c')
        print(''.join(ans))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()