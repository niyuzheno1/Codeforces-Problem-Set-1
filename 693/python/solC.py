import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        scores = [0] * n
        ans = 0
        for i in range(n-1, -1, -1):
            if i + a[i] < n:
                scores[i] = scores[i+a[i]]
            scores[i] += a[i]
            ans = max(scores[i],ans)
        print(ans)
        

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()