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



def main():
    findall([['0','0'],['0','0']],[])
    for _ in range(int(input())):
        n,m = list(map(int,input().split()))
        arr = []
        for i in range(0,n):
            x = input()
            x = list(x)
            arr.append(list(map(int,x)))
        ans = []
        greedy = []
        
        num = 0
        for i in range(0,n):
            for j in range(0,m):
                num += arr[i][j]
        if num == n*m:
            ans.append((0,0))
            ans.append((0,1))
            ans.append((1,0))
            arr[0][0] = arr[0][1] = arr[1][0] = 0
            


        for i in range(0,n-1):
            for j in range(0,m-1):
                num = 0
                for k in range(0,2):
                    for l in range(0,2):
                            num = num +  arr[i+k][j+l]
                greedy.append((num,i,j))
        greedy.sort(reverse=True)
        while True:
            for ii in range(0,len(greedy)):
                    mx , i,j = greedy[ii]
                    if mx == 4:
                        continue
                    idx = 0
                    num = 0
                    for k in range(0,2):
                        for l in range(0,2):
                                num = num +  arr[i+k][j+l]
                    
                    if num == 0 or num == 1:
                        greedy[ii] = (num,i,j)
                        continue
                    
                    for k in range(0,2):
                        for l in range(0,2):
                            idx = idx *2 
                            idx += arr[i+k][j+l]
                    a = solution[idx]
                    for x in a:
                        ans.append((x[0] + i, x[1] + j))
                        
                    for k in range(0,2):
                        for l in range(0,2):
                            arr[i+k][j+l] = 0
            ngreedy = []
            for x in greedy:
                if x[0] == 4:
                     u, i, j = x
                     num = 0
                     for k in range(0,2):
                        for l in range(0,2):
                            num = num +  arr[i+k][j+l]
                     ngreedy.append((num,i,j))
                if x[0] == 1:
                    u, i, j = x
                    num = 0
                    for k in range(0,2):
                        for l in range(0,2):
                            num = num +  arr[i+k][j+l]
                    if num == 1:
                        recorded = None
                        for k in range(0,2):
                            for l in range(0,2):
                                if arr[i+k][j+l] == 1:
                                    recorded = (k,l)
                                    ans.append((i+k,j+l))
                                arr[i+k][j+l] = 0
                               
                        for k in range(0,2):
                            for l in range(0,2):
                                if(k != recorded[0] and l != recorded[1]):
                                    arr[i+k][j+l] = 1
                                    arr[i+k][recorded[1]] = 1
                                    ans.append((i+k, j+l))
                                    ans.append((i+k, recorded[1]))
                        num = 2
                    ngreedy.append((num,i,j))
            ngreedy.sort(reverse=True)
            greedy = ngreedy
            if greedy == []:
                break
        
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