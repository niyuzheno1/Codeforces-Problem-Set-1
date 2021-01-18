import sys
import argparse




def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        def getval(x):
            ans = 0
            if x <= 0 or x >= n-1:
                return 0
            if a[x] > a[x-1] and a[x] > a[x+1]:
                return 1
            if a[x] < a[x-1] and a[x] < a[x+1]:
                return 1
            return 0
        init = [0]*n
        def diff(x,y):
            ret = 0
            if x > 0:
                ret += y[0]-init[x-1]
            if x < n-1:
                ret += y[2]-init[x+1]
            return y[1]-init[x] + ret
        ans = 0
        for i in range(n):
            init[i] = getval(i)            
            ans += init[i]  
        s = ans
        for i in range(n):
            lefx = a[i] if i == 0 else a[i-1]
            rigx = a[i] if i == n-1 else a[i+1]
            r = a[i]
            y = []
            a[i] = lefx
            y.append(getval(i-1))
            y.append(getval(i))
            y.append(getval(i+1))
            s = min(s, ans+diff(i,y))
            a[i] = rigx
            y.append(getval(i-1))
            y.append(getval(i))
            y.append(getval(i+1))
            s = min(s, ans+diff(i,y))
            a[i] = r
        print(s)




if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()