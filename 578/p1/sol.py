import sys
import argparse


def main():
    n = int(input())
    s = input()
    a = {}
    for j in range(0,10):
        a[j] = 0
    for i in range(0,n):
        if s[i] == 'L':
            for j in range(0,10):
                if a[j] == 0:
                    a[j] = 1
                    break
        elif s[i] == 'R':
            for j in range(9,-1,-1):
                if a[j] == 0:
                    a[j] = 1
                    break
        else:
            x = int(s[i])
            a[x] = 0
    ans = ""
    for i in range(0,10):
        ans = ans + str(a[i])
    print(ans)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()