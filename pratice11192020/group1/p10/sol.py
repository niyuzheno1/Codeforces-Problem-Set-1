import sys
import argparse


def main():
    for i in range(int(input())):
        s = input()
        n = len(s)
        a = []
        c = 0
        for i in range(0,n):
            if s[i] == '1':
                c = c + 1
            else:
                a.append(c)
                c = 0
        a.append(c)
        a.sort(reverse=True)
        ans = 0
        for i in range(len(a)):
            if i % 2 == 0:
                ans += a[i]
        print(ans)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()