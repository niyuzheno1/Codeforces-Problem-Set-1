import sys
import argparse

def roundup(u,v):
    if u % v == 0:
        return int(u/v)
    return int(u/v) + 1
def main():
    for _ in range(int(input())):
        n,x = list(map(int,input().split()))
        a = list(map(int,input().split()))
        rmax = 0
        rmin = 0
        rmin = roundup(sum(a),x)
        for i in range(0,len(a)):
            rmax += roundup(a[i],x)
        print("{} {}".format(rmin, rmax))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()