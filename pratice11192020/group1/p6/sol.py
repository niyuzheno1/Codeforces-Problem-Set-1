import sys
import argparse


def main():
    for _ in range(int(input())):
        nk = list(map(int,input().split()))
        a = list(map(int,input().split()))
        a.sort(reverse=True)
        k = nk[1]+1
        n = nk[0]
        if n == 1:
            print("0")
            continue
        i = 0
        sum = 0
        while i < n and k > 0:
            sum = sum + a[i]
            k = k - 1
            i = i +1
        print(sum)
        


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()