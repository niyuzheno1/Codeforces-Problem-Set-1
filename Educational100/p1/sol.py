import sys
import argparse


def main():
    for _ in range(int(input())):
        a = list(map(int, input().split()))
        sa = sum(a)
        if sa % 9 == 0:
            ones = sa//9
            for i in range(0,3):
                a[i] -= ones
            flag = True
            for i in range(0,3):
                if a[i] < 0:
                    flag = False
            sb = sum(a)
            if sb % 6 != 0 or sb//6 != ones:
                flag = False
            if flag:
                print("YES")
            else:
                print("NO") 
        else:
            print("NO")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()