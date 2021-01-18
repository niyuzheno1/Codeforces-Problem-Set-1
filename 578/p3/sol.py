import sys
import argparse

def gcd(x, y): 
   while(y): 
       x, y = y, x % y 
   return x 

def main():
    n,m,q = list(map(int,input().split()))
    u = gcd(n,m)
    nn = n//u
    nm = m//u
    def getsector(u, v):
        if u == 1:
            addone = 1 if v % nn > 0 else 0
            return v//nn + addone
        else:
            addone = 1 if v % nm > 0 else 0
            return v//nm + addone
    for i in range(0, q):
        sx,sy,ex,ey = list(map(int,input().split()))
        sectornumbers = getsector(sx,sy)
        sectornumbere = getsector(ex,ey)
        if sectornumbers == sectornumbere:
            print("YES")
        else:
            print("NO")
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()