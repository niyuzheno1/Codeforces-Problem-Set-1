import sys
import argparse


def main():
    table = {}
    for i in range(0, 1000):
        if i * 3 > 1000:
            break
        for j in range(0,1000):
            if j * 5 + i * 3 > 1000:
                break
            for k in range(0,1000):
                if i * 3 + j * 5 + k * 7 > 1000:
                    break
                table[i * 3 + j * 5 + k * 7] = [i,j,k]
    for _ in range(int(input())):
        n = int(input())
        if (n not in table):
            print(-1)
            continue

        u = table[n]
        
        u = map(str,u)
        print(" ".join(u))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()