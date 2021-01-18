import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        x = []
        for i in range(n):
            u = (i+2)%n
            if u == 0:
                u = n
            x.append(u)
        x = list(map(str,x))
        print(" ".join(x))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()