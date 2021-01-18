import sys
import argparse


def main():
    for _ in range(int(input())):
        x, y = list(map(int, input().split()))
        # if x == y + 1:
        #     print("{} {}".format(y, y))
        # elif x <= y:
        #     print("0 {}".format(y))
        # elif x > y:
        #     print("{} 1".format(x-y))
        # if x == y + 1:
        #     print("{} {}".format(y, y))
        # elif x == y and x > 1:
        #     print("{} {}".format(x,x))
        # elif x == y:
        #     print("0 1")
        if x <= y:
            print("{} {}".format(x-1,y))
        elif x > y:
            print("{} {}".format(x-1,y))
        


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()