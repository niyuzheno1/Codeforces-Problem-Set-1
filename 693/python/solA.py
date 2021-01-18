import sys
import argparse

def count(x):
    cnt = 1
    while x %2 == 0:
        cnt *= 2
        x /= 2
    return cnt

def main():
    for _ in range(int(input())):
        w, h, n = list(map(int,input().split()))
        w = count(w)
        h = count(h)
        if w * h >= n:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()