import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        s = input()
        ans1 = 0 
        c = '1'
        flipping = False
        for i in range(0, n):
            if s[i] != c and not flipping:
                ans1 = ans1 + 1
                flipping = True
            elif s[i] == c and flipping == True:
                flipping = False

            c = '0' if c == '1' else '1'
        ans2 = 0
        c = '0'
        flipping = False
        for i in range(0, n):
            if s[i] != c and not flipping:
                ans2 = ans2 + 1
                flipping = True
            elif s[i] == c and flipping == True:
                flipping = False
                
            c = '0' if c == '1' else '1'
        print(min(ans1, ans2))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()