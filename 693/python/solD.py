import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        scores = [0]*2
        a = sorted(a,reverse=True)
        for i in range(0, n):
            if (i+a[i])%2 == 0:
                scores[i%2] += a[i]
        if scores[0] > scores[1]:
            print("Alice")
        if scores[0] < scores[1]:
            print("Bob")
        if scores[0] == scores[1]:
            print("Tie")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()