import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        b = list(a)
        a.sort()
        ansx = -1 
        i = 0
        while i < n:
            j = i
            while j < n and a[j] == a[i]:
                j = j + 1
            if j - i == 1:
                ansx = a[i]
                break
            i = j
        ans = -2
        for i in range(0,n):
            if b[i] == ansx:
                ans = i
        print(ans+1)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()