import sys
import argparse

s = ""
def main():
    global s
    for _ in range(int(input())):
        nq = list(map(int, input().split()))
        n = nq[0]
        q = nq[1]
        s = input()
        lone = -1 
        lzeros = -1
        rzeros = -1 
        rone = -1
        if s[0] == '0':
            lzeros = 0
            for i in range(0,n):
                if s[i] == '1':
                    lone = i
                    break
        else:
            lone = 0
            for i in range(0,n):
                if s[i] == '0':
                    lzeros = i
                    break
        if s[n-1] == '0':
            rzeros = n-1
            for i in range(n-1,-1,-1):
                if s[i] == '1':
                    rone = i
                    break
        else:
            rone = n-1
            for i in range(n-1,-1,-1):
                if s[i] == '0':
                    rzeros = i
                    break
        ml = { '0' : lzeros, '1' : lone}
        mr = { '0' : rzeros, '1' : rone}
        for i in range(0,q):
            lr = list(map(int, input().split()))
            l = lr[0] -1
            r = lr[1] -1
            if ml[s[l]] < l or mr[s[r]] > r:
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