import sys
import argparse

def f(x):
    return x*x
def g(x):
    return 2*x*(x+1)

def main():
    n = int(input())
    if n % 2 == 0:
        print(f(n//2+1))
    else:
        print(g((n+1)//2))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()