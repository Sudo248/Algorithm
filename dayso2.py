t = int(input())
while t > 0:
    t-=1
    n = int(input())
    a = [int(i) for i in input().split()]
    res = []
    m = n
    while n > 0:
        res.append(a)
        b = []
        for i in range(n-1):
            b.append(a[i]+a[i+1])
        a = b
        n-=1
    for i in range(m-1,-1,-1):
        a = res[i]
        n = len(a)
        print("[",end="")
        for j in range(n-1):
            print(a[j],end=" ")
        print(str(a[n-1])+"]",end=" ")
    print()