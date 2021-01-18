import sys
import argparse
import math

def main():
    for _ in range(int(input())):
        a = input()
        b = input()
        la = len(a)
        lb = len(b)
        lc = la*lb//math.gcd(la,lb)
        sa = ""
        sb = ""
        for i in range(0, lc//la):
            sa += a
        for i in range(0, lc//lb):
            sb += b
        if sa == sb:
            print(sa)
        else:
            print(-1)



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()