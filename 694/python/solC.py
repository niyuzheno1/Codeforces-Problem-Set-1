import sys
import argparse
import math

def lcm(x,y):
    return x*y/math.gcd(x,y)

def main():
    n = int(input())
    a = list(map(int, input().split()))
    for k in range(1,5):
        b = [1] * n
        c = [0] * n
        for i in range(0,n):
            for j in range(0,n):
                u = lcm(a[i],a[j])/math.gcd(a[i],a[j])
                if int(math.sqrt(u))**2 == u:
                    b[i] *= a[j]
                    c[i] = c[i]+1
        a = b
        print(a)
        print(c)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()