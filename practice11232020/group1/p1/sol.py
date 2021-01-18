import sys
import argparse


def main():
    for _ in(range(int(input()))):
        ab = list(map(int,input().split()))
        diff = ab[0]-ab[1] if ab[0]-ab[1] > 0 else ab[1]-ab[0]
        steps = diff // 10
        if diff  % 10 > 0:
            steps = steps + 1
        print(steps)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()