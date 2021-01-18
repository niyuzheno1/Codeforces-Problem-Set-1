import sys
import argparse


def manhattan(u,v):
    return abs(u[0]-v[0]) + abs(u[1] - v[1])

def main():
    for _ in range(int(input())):
        n, k = list(map(int, input().split()))
        a = []
        for j in range(0,n):
            a.append(list(map(int, input().split())))
        flag = False
        for i in range(0,n):
            cnt = 0
            for j in range(0,n):
                cnt = cnt + 1 if manhattan(a[i],a[j]) <= k else cnt
            if cnt == n:
                flag = True
        if flag:
            print("1")
        else:
            print("-1")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()