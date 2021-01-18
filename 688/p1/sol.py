import sys
import argparse


def main():
    for _ in range(int(input())):
        n,m = list(map(int, input().split()))
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        ans = 0
        for i in range(0,len(b)):
            if b[i] in a:
                ans = ans + 1
        print(ans)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()