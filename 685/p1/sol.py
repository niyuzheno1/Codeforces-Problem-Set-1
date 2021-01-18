import sys
import argparse
import math

def proc(n):
    global f
    if n in f:
        return f[n]
    else:
        f[n] = n+1
    for j in range(2,n):
        if n % j == 0:
            f[n] = min(f[n],proc(n/j)+1)
    f[n] = min(f[n], proc(n-1) + 1)
    return f[n]

def main():
    for _ in range(int(input())):
        n = int(input())
        if n == 1:
            print(0)
        elif n == 2:
            print(1)
        elif n == 3:
            print(2)
        elif n % 2 == 0:
            print(2)
        elif n % 2 == 1:
            print(3)
        


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()