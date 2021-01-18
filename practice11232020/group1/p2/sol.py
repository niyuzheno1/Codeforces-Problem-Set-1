import sys
import argparse


def main():
    for _ in(range(int(input()))):
        abxyn = list(map(int,input().split()))
        products1 = 0
        products2 = 0 
        a,b,x,y,n = abxyn
        m = n
        if (n - (a-x))>0:
            products1 = x
            n -= (a-x)
        else:
            products1 = a-n
            n = 0
        if (n-(b-y))>0:
            products1 *= y
        else:
            products1 *= (b-n)
        n = m
        if (n-(b-y))>0:
            products2 = y
            n = n - (b-y)
        else:
            products2 = (b-n)
            n = 0
        if (n - (a-x))>0:
            products2 *= x
        else:
            products2 *= a-n
        print(min(products1,products2))
            


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()