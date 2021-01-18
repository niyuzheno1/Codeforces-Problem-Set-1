# your code goes here
for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    num = int((n-1)/2)
    num2 = int((n+1)/2)
    if n % 2 == 0:
        num2 = num2+1

    num = num * k 
    print(sum(arr[num::num2]))
