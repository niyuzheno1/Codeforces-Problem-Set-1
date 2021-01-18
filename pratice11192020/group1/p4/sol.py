import sys
import argparse

def verify(s, ans, n):
    for i in range(0,n):
        sx = s[i:i+n]
        if sx == ans:
            return True
    return False

def main():
    for _ in range(int(input())):
        n = int(input())
        s = input()
        ans = '0' * n
        ans2 = '1' * n
        p1 = verify(s, ans, n)
        p2 = verify(s, ans2, n)
        if p1 == True:
            print(ans)       
        elif p2 == True:
            print(ans2)
        else:
            print(ans)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()