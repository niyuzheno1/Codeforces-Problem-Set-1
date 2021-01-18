import sys
import argparse
import copy
solution = { i : [5 for i in range(0,17)] for i in range(0,16) }

dx = [1,-1,0,0,0]
dy = [0,0,1,-1,0]

def within(x,y):
    return x <= 1 and y <= 1 and x >= 0 and y >= 0

def decode(x):
    ret = ""
    for y in x:
        ret += ''.join(y)
    return int(ret, 2)


def encode(x):
    u = bin(x)[2:].zfill(4)
    ret = []
    a = []
    for i in range(0,2):
        a.append(int(u[i]))
    b = []
    for i in range(2,4):
        b.append(int(u[i]))
    ret.append(a)
    ret.append(b)
    return ret

def findall(x, steps):
    de = decode(x)
    if len(solution[de]) > len(steps):
        solution[de] = steps
    else:
        return
    for i in range(0,2):
        for j in range(0,2):
            nx = copy.deepcopy(x)
            s = copy.deepcopy(steps)
            for l in range(0,5):
                if within(i+dx[l], j + dy[l]):
                    nx[i+dx[l]][j + dy[l]] = '0' if nx[i+dx[l]][j + dy[l]] == '1' else '1'
                    s.append((i+dx[l],j + dy[l]))
            findall(nx, s)    
    return


solx = { i : [] for i in range(0,16) }
soly = { i : [] for i in range(0,16) }

def pickingtwoandthree():
    zerosx = [[0,0],[0,0]]
    for x in solution:
        y = encode(x)
        ret = 0
        for i in range(0,2):
            for j in range(0,2):
                ret += y[i][j]
        if ret == 0 or ret == 2 or ret == 3:
            solx[x] = zerosx
            soly[x] = solution[x]

def solvingonepast():
    targetx = [[0,0],[0,0]]
    onesx = [['0','0'], ['0', '0']]
    for i in range(0,2):
        for j in range(0,2):
            if i == 0 and j == 0:
                continue
            onesx[i][j] = '1'
            for k in range(0,2):
                for l in range(0,2):
                    targetx[k][l] = 0
            action = []
            for k in range(0,2):
                for l in range(0,2):
                    if k == 0 and l == 0:
                        continue
                    action.append((k,l))
                    if onesx[k][l] == '1':
                        targetx[k][l] = 0
                    else:
                        targetx[k][l] = 1
            x = decode(onesx)
            solx[x] = targetx
            soly[x] = action
            onesx[i][j] = '0'
    
    onesx[0][0] = '1'
    x = decode(onesx)
    solx[x] = [[0,1],[1,0]]
    soly[x] = [(0,0), (0,1), (1,0)]

def solvingone():
    targetx = [[0,0],[0,1]]
    onesx = [['0','0'], ['0', '0']]
    for i in range(0,2):
        for j in range(0,2):
            onesx[i][j] = '1'
            action = []
            for k in range(0,2):
                for l in range(0,2):
                    if onesx[k][l] == '0':
                        action.append((k,l))
            action.append((0,0))
            action.append((1,0))
            action.append((0,1))
            x = decode(onesx)
            solx[x] = targetx
            soly[x] = action
            onesx[i][j] = '0'
    soly[1] = [] 

def solvingfour():
    targetx = [[0,0],[0,1]]
    onesx = [['1','1'], ['1', '1']]
    x = decode(onesx)
    solx[x] = targetx
    soly[x] = [(0,0), (0,1), (1,0)]

def cadd(c0, c1):
    return (c0[0]+c1[0], c0[1] + c1[1])

def main():
    findall([['0','0'],['0','0']],[])
    solvingone()
    solvingfour()
    pickingtwoandthree()
    for _ in range(int(input())):
        n,m = list(map(int,input().split()))
        arr = []
        for i in range(0,n):
            x = input()
            x = list(x)
            arr.append(list(map(int,x)))
        ans = []
        for i in range(0,n-2):
            for j in range(0, m):
                nj = j + 1
                if j == m-1:
                    nj = j - 1
                if arr[i][j] == 1:
                    arr[i][j] ^= 1
                    arr[i+1][j] ^= 1
                    arr[i+1][nj] ^= 1
                    ans.append((i,j))
                    ans.append((i+1,j))
                    ans.append((i+1,nj))
        for i in range(0,m-2):
            if arr[n-1][i] == 1 and arr[n-2][i] == 1:
                arr[n-1][i] ^= 1
                arr[n-2][i] ^= 1
                arr[n-2][i+1] ^= 1
                ans.append((n-1,i))
                ans.append((n-2,i))
                ans.append((n-2,i+1))
            elif arr[n-1][i] == 1:
                arr[n-1][i] ^= 1
                arr[n-1][i+1] ^= 1
                arr[n-2][i+1] ^= 1
                ans.append((n-1,i))
                ans.append((n-1,i+1))
                ans.append((n-2,i+1))
            elif arr[n-2][i] == 1:
                arr[n-2][i] ^= 1
                arr[n-1][i+1] ^= 1
                arr[n-2][i+1] ^= 1
                ans.append((n-2,i))
                ans.append((n-1,i+1))
                ans.append((n-2,i+1))
        i = n-2
        j = m-2
        tmp = []
        for k in range(0,2):
            for l in range(0,2):
                tmp.append(str(arr[i+k][j+l]))
        tmpx = decode(tmp)
        actions = solution[tmpx]
        for a in actions:
            ans.append(cadd((i,j),a))
        print(int(len(ans)/3))
        for x in range(0,len(ans), 3):
            nx = x + 3
            line = ""
            for y in range(x, nx):
                line += str(ans[y][0]+1)
                line += " "
                line += str(ans[y][1]+1)
                line += " "
            print(line)

                
                

    
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()