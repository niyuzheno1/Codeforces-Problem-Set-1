import sys
import argparse
import copy

def main():
    n = int(input())
    a = []
    s = 0 
    for i in range(n):
        x = list(map(int,input().split()))
        a.append(x)
        s += x[1]
    sorted(a, key=lambda x: x[0]-x[1])
    ans = [0] * (n+1)
    for i in range(n):
        for l in range(100):
            for r in range(l, 100):
                t = []
                u = []
                for j in range(n):
                    if a[j][1] <= r and a[j][1] >= l:
                        t.append(list(a[j]))
                    else:
                        u.append(list(a[j]))
                m = len(t)
                ptt = list(t)
                for j in range(0,m):
                    t = copy.deepcopy(ptt)
                    ret = 0.0
                    for k in range(0, len(u)):
                        tt = u[k][1]/2
                        for ii in range(0,j+1):
                            if t[ii][0] - t[ii][1] > 0:
                                t[ii][1] = min(t[ii][1]+tt,t[ii][0])
                                break
                        t = sorted(t,  key=lambda x: x[0]-x[1])
                    for ii in range(0,j+1):
                        ret += t[ii][1]
                    ans[j+1] = max(ans[j+1], ret)
    out = []
    for i in range(1,n+1):
        out.append(ans[i])
    print(" ".join(list(map(str, out))))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()