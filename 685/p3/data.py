import sys
import argparse
import numpy as np
def GenerateAnArray(n, func):
    ret = []
    for i in range(0,n):
        ret.append(func(i))
    return ret

def OutputARandomArray(arr):
    res = ""
    for i in range(0,len(arr)):
        res += str(arr[i])
        res += " "
    print(res)

def OutputAString(arr):
    print(''.join(arr))

def GetRandomNumber(y, z):
    def Gen(x):
        return np.random.randint(low = y, high = z)
    return Gen

## convert int array to string array list(map(str,arr))
## array.sort(reverse=True) 
def example():
    print("1")
    genrand = GetRandomNumber(1,1000)
    arr = GenerateAnArray(2, genrand)
    OutputARandomArray(arr)
    arr2 = GenerateAnArray(arr[0]*arr[1], genrand)
    arr2.sort(reverse=True) 
    OutputARandomArray(arr2)
def example2():
    print("1")
    genrand = GetRandomNumber(1,1000)
    gench = GetRandomNumber(0,2)
    arr = GenerateAnArray(2, genrand)
    OutputARandomArray(arr)
    for i in range(0, arr[0]):
        u = GenerateAnArray(arr[1], gench)
        u = list(map(str,u))
        OutputAString(u)  
def tostralpha(x):
    return str(chr(97+x))
def main():
    print("1")
    for i in range(1):
        genrand = GetRandomNumber(1,1000000)
        genranda = GetRandomNumber(0,2)
        nk = GenerateAnArray(2, genrand)
        nk[1] = (nk[1] % nk[0] )+ 1
        OutputARandomArray(nk)
        s = GenerateAnArray(nk[0], genranda)
        s = list(map(tostralpha,s))
        print(''.join(s))
        
        s = GenerateAnArray(nk[0], genranda)
        s = list(map(tostralpha,s))
        
        print(''.join(s))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdout = open(args.filename, "w")
    else:
        sys.stdout = open("input.txt", "w")
    main()