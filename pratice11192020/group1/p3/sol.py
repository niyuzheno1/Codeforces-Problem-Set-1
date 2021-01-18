import sys
import argparse
import copy
f = {}
timesx = 0
def make(action,torch1, torch2, x, y):
    global timesx,f
    u = min(torch1, torch2)
    timesx = timesx + 1
    if u > 10 or len(action) > 16:
        return
    if u in f:
        if len(action) <= len(f[u]):
            f[u] =  copy.deepcopy(action)
    else:
        f[u] =  copy.deepcopy(action)
    if torch1 > 0:
        make(action + [(torch1,torch2)], torch1-1, torch2 + x, x,y)
    if torch2 > 0:
        make(action + [(torch1,torch2)], torch1+y, torch2 - 1, x,y)

def sim(x, y, k):
    minimum = k + y * k 
    print(minimum)
    t1, t2 = (1,0)
    while t2 < minimum:
        while t1 > 0:
            t1 = t1 -1
            t2 += x
        while t2 > 0:
            t1 += y
            t2 = t2 -1
    print(t1,t2) 

def sim2(x,y,k):
    queue = [(1,0)]
    explored = {}
    explored[(1,0)] = 0
    while queue:
        t = queue.pop(0)
        if t[0] < 0 or t[1] < 0:
            continue
        if t[0] >= 5*k or t[1] >= 5*k:
            continue
        if (t[0]-1,t[1]+x) in explored:
            if explored[(t[0]-1,t[1]+x)] > min(explored[(t[0]-1,t[1]+x)], explored[t] + 1):
                explored[(t[0]-1,t[1]+x)] = min(explored[(t[0]-1,t[1]+x)], explored[t] + 1)
                queue.append((t[0]-1,t[1]+x))
        else:
            explored[(t[0]-1,t[1]+x)] = explored[t] + 1
            queue.append((t[0]-1,t[1]+x))
        if (t[0]+1,t[1]-y) in explored:
            if explored[(t[0]+1,t[1]-y)] > min(explored[(t[0]+1,t[1]-y)], explored[t] + 1):
                explored[(t[0]+1,t[1]-y)] = min(explored[(t[0]+1,t[1]-y)], explored[t] + 1)
                queue.append((t[0]+y,t[1]-1))
        else:
            explored[(t[0]+1,t[1]-y)] = explored[t] + 1
            queue.append((t[0]+1,t[1]-y))
    print(explored)
        


def main():
    make([], 1, 0, 2, 1)
    for i in range(0,10):
        if i in f:
            print( "{}:{}".format(i,f[i]))
    sim2(2,1,5)
    pass


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()