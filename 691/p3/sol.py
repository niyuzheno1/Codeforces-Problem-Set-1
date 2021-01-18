import sys
import argparse
import math

def main():
    n, m = list(map(int, input().split()))
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a = sorted(a)
    r = []
    if n < 2:
        for i in range(0,m):
            ans = a[0]+b[i]
            for j in range(0,n):
                ans = math.gcd(ans, a[j] + b[i])
            r.append(ans)
    else:
        base = a[1]-a[0]
        for j in range(2,n):
            base = math.gcd(base, a[j] - a[0])
        for i in range(0,m):
            ans = a[0]+b[i]
            r.append(math.gcd(ans, base))
    print(' '.join(list(map(str,r))))
    
        
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()