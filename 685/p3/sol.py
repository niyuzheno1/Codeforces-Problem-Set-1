import sys
import argparse


def main():
    for _ in range(int(input())):
        nk = list(map(int,input().split()))
        n = nk[0]
        k = nk[1]
        s = input()
        t = input()
        sd = {x: 0 for x in s}
        td = {x: 0 for x in t}
        for i in range(0,n):
            sd[s[i]] = sd[s[i]] + 1
        for i in range(0,n):
            td[t[i]] = td[t[i]] + 1
        for x in sd:
            if x in td:
                tx = sd[x] - td[x]
                ty = sd[x]
                if tx < 0:
                    td[x] -= sd[x]
                    sd[x] = 0
                else:
                    td[x] = 0
                    sd[x] = tx
        for x in sd:
            for y in td:
                if x < y:
                    if sd[x] >= k and td[y] >= k:
                        amount = min(sd[x], td[y]) // k
                        sd[x] = sd[x] - amount*k
                        td[y] = td[y] - amount*k
        flag = True
        for x in sd:
            if sd[x] > 0:
                flag = False
        for x in td:
            if td[x] > 0:
                flag = False
        if flag == True:
            print("Yes")
        else:
            print("No") 


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()