import numpy as np

arr = np.array([[0,1],[1,1]])
t = int(input())
while t:
    t -= 1
    n = int(input())
    res = np.linalg.matrix_power(arr,n)
    mod = 1000000007
    x = int(res[0][1])
    print(x%mod)
