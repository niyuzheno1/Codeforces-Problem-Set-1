import sys
import argparse

def extend(cor):
    global d,k
    u = (cor[0]+k,cor[1])
    if u[0]*u[0] + u[1]*u[1] > d * d:
        u = None
    v = (cor[0],cor[1]+k)
    if v[0]*v[0] + v[1]*v[1] > d * d:
        v = None
    return u,v

f = {}    

def dfs(cor,who):
    global f
    
    u,v = extend(cor)
    if u == None and v == None:
        return (not who)
    if u != None:
        u = dfs(u, not who)
    else:
        u = not who
    if v != None:
        v = dfs(v, not who)
    else:
        v = not who
    if who == True:
        f[cor] = (u or v)
    else:
        f[cor] = (u and v)
    return f[cor]

def main():
    global f
    global d,k
    for _ in range(int(input())):
        f = {}
        dk = list(map(int, input().split()))
        d = dk[0]
        k = dk[1]
        # {Ashish : True, Utkarsh : False}
        print(str(dk) + ":"+ str(dfs((0,0), True)))
        #print(f)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()