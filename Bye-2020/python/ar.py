def main():
    for _ in range(int(input())):
        n = int(input())
        x = list(map(int,input().split()))
        a = [0] * n
        # a[0] is even
        for i in range(0,n):
            if (x[i]+i) % 2 == 0:
                a[i] = x[i]
            else:
                a[i] = x[i]+1
        diversity = 0
        tmp = 0
        a = sorted(a)
        for i in range(0,n-1):
            if a[i] != a[i+1]:
                tmp = tmp + 1
        diversity = max(diversity, tmp)
        for i in range(0,n):
            if (x[i]+i+1) % 2 == 0:
                a[i] = x[i]
            else:
                a[i] = x[i]+1
        tmp = 0
        a = sorted(a)
        for i in range(0,n-1):
            if a[i] != a[i+1]:
                tmp = tmp + 1
        diversity = max(diversity, tmp)
        print(diversity+1)