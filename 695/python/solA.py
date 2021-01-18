import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        ans = []
        cur = 9
        if n == 1:
            print(9)
            continue
        if n == 2:
            print(98)
            continue
        if n == 3:
            print(989)
            continue
        if n == 4:
            print(9890)
            continue
        if n == 5:
            print(98901)
            continue
        ans.append(9)
        ans.append(8)
        cur = 9
        for i in range(n):
            ans.append(cur)
            cur = cur + 1
            if cur == 10:
                cur = 0
        print("".join(list(map(str,ans))))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()