n = 9
k = 6
u = 1
a = []
for i in range(0,k):
    a.append(u)
    u = u+1
u = u -1
for i in range(0,n-k):
    u = u-1
    a.append(u)
print(' '.join(list(map(str,a))))