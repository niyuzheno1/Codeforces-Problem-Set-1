import sys
import argparse


def main():
    for i in range(int(input())):
        n = int(input())
        s = input()
        print(''.join(sorted(s)))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()