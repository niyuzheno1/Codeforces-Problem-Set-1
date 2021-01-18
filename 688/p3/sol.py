import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        board = []
        for i in range(0, n):
            a = []
            s = input()
            for i in range(0,n):
                a.append(s[i])
            board.append(a)
        def vmax(x,y,z):
            ret = 0
            if x != -1 and x != n:
                ret = max(ret, abs(x-z))
            if y != -1 and y != n:
                ret = max(ret, abs(y-z))
            return ret 
        lrec = {}
        rrec = {}
        trec = {}
        brec = {}
        area = {}
        for i in range(0,10):
            lrec[str(i)]  = trec[str(i)] = n+1
            rrec[str(i)] = brec[str(i)] = -1
            area[str(i)] = 0
        for i in range(0,n):
            for j in range(0,n):
                lrec[board[i][j]] = min(lrec[board[i][j]], j)
                trec[board[i][j]] = min(trec[board[i][j]], i)
                rrec[board[i][j]] = max(rrec[board[i][j]], j)
                brec[board[i][j]] = max(brec[board[i][j]], i)
        for i in range(0,n):
            for j in range(0,n):
                d = board[i][j]
                if d == '0':
                    b = 100
                res = vmax(trec[d],brec[d],i)*max(j, n-1-j)
                res2 = vmax(rrec[d],lrec[d],j)*max(i, n-1-i)
                res = max(res,res2)
                area[d] = max(area[d], res)
        ans = []
        for i in range(0, 10):
           ans.append(str(area[str(i)]))
        print(" ".join(ans))



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()