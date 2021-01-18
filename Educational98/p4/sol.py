import sys
import argparse

def decode(x,n):
    ret = [0 for i in range(0,n)]
    i = 0
    while x > 0:
        ret[i] = x & 1;
        x //= 2
        i = i + 1
    return ret


def validity(x, n):
    y = [0 for i in range(0,n+2)]
    z = [0 for i in range(0,n+2)]
    for i in range(0,n):
        y[i+1] = x[i]   
    y[0] = y[n+1] = 1 
    for i in range(1,n+1):
        if y[i] == 1:
            m = 0
            for j in range(0, i):
                if y[j] == 1:
                    m = j
            r = 0
            for j in range(n+1, i, -1):
                if y[j] == 1:
                    r = j
            mindist = min(i-m-1, r - i-1)
            for i in range( i - mindist, i + mindist+1):
                z[i] = 1
                y[i] = 1
    for i in range(1,n+1):
        if z[i] == 0:
            return False
    
    return True
            

def main2():
    cnt = 0
    N = 7
    for i in range(0,2**N):
        tmp = decode(i,N)
        if (validity(tmp,N)) == True:
            cnt = cnt + 1
    print(cnt)

def main():
    f = [0 for i in range(0, 200010)]
    a, b  = 1,1
    n = int(input())
    for i in range(2, n):
        tmpb = b
        b = a+b
        a = tmpb    
    
    MODN = 998244353
    ANS = 998244351
    ans = pow(1<<n, ANS, MODN) % MODN
    ans = (ans * b)% MODN
    print(ans)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()