greedy = []
        for i in range(0,n-1):
            for j in range(0, m-1):
                num = 0
                for k in range(0,2):
                    for l in range(0,2):
                            num = num +  arr[i+k][j+l]
                greedy.append((num,i,j))
        greedy.sort(reverse=True)
        for i in range(0, len(greedy)):
            mx , i,j = greedy[i]
            num = 0
            for k in range(0,2):
                for l in range(0,2):
                        num = num +  arr[i+k][j+l]
            if num == 0:
                continue
            tmp = []
            for k in range(0,2):
                for l in range(0,2):
                    tmp.append(str(arr[i+k][j+l]))
            idx = decode(tmp)
            a = solution[idx]
            for x in a:
                ans.append((x[0] + i, x[1] + j))
                
            for k in range(0,2):
                for l in range(0,2):
                    arr[i+k][j+l] = 0