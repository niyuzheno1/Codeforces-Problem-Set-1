import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        u = {1 : 0, 2:0}
        sum = 0
        for x in a:
            u[x] = u[x] + 1
            sum = sum + x
        flag = False
        for i in range(0, u[1]+1):
            for j in range(0, u[2]+1):
                if sum - (i+2*j) == i+2*j:
                    flag = True
                if flag:
                    break
            if flag:
                break
        if flag:
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