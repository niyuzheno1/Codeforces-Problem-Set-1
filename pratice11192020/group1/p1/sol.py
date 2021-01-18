import sys
import argparse


def generatingpatterns():
    map = {}
    for i in range(1,100):
        for j in range(i, 100):
            for a in range(1,200):
                flag = True
                for k in range(i,j+1):
                    if k % a < a/2:
                        flag = False
                if flag == True:
                    map[(i,j)] = a
                    break
    line = "x"
    line += (',')
    for i in range(1,99):
        line += ("{},".format(i))
    line += ("99")

    print(line)
    for i in range(1,100):
        line = ""
        line += ("{},".format(i))
        for j in range(1, 100):
            tmp = "{}"
            if j != 99:
                tmp += ","
            if (i,j) in map:

                # line += (tmp.format(map[(i,j)]))
                if map[(i,j)] > 0:
                    line += (tmp.format((i,j)))
                else:
                    line += (tmp.format(0))
            else:
                line += (tmp.format(0))
        print(line)
    return 

def mainx():
    for _ in range(int(input())):
        lr = list(map(int,input().split()))
        l = lr[0]
        r = lr[1] 
        if l * 2 > r:
            print("YES")
        else:
            print("NO")

def main():
    mainx()

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()