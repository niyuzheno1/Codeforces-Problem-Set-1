import sys
import argparse

def roundup(u,v):
    if u % v == 0:
        return int(u/v)
    return int(u/v) + 1
def div(u,v):
    return int(u/v)
def prev(u,v):
    u = u-1
    if u < 0:
        u = u + v
    return u
def nexti(u,v):
    u = u + 1
    return u % v
def main():
    n = 100
    impo = 4
    t = 50
    a = [2] * n
    b = [0] * n
    for i in range(0, t):
        for j in range(0,n):
            b[j] = 0
        for j in range(0,n):
            if j == impo:
                b[nexti(j,n)] += a[j]
                continue    
            b[prev(j,n)] += div(a[j],2)
            b[nexti(j,n)] += roundup(a[j],2)
        
        for j in range(0,n):
            a[j] = b[j]
        print(" ".join(list(map(str, a))))


if __name__ == "__main__":
    sys.stdout = open("patten.txt", "w")
    main()