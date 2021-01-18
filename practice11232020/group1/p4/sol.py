import sys
import argparse


def main():
    for _ in(range(int(input()))):
        ns = list(map(int,input().split()))
        n, s = ns
        ss = str(n)
        l = "1" + len(ss) * "0"
        l = int(l)
        steps = l - n
        ss = list(map(int,list(ss)))
        lss = len(ss)
        if sum(ss) <= s:
            print('0')
        else:
            strx = ""
            tmpsum = 0
            for i in range(0,lss):
                for j in range(ss[i]+1, 10):
                    tmp = strx + str(j) + "0" * (lss-i-1)
                    tmp = int(tmp)
                    tsum = tmpsum + j
                    if tsum <= s:
                        steps = min(steps, tmp - n)
                strx += str(ss[i])
                tmpsum += ss[i]
            print(steps)



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()