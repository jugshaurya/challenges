
import math


def primeFactors(n):
    arr = []
    while n % 2 == 0:
        arr.append(2)
        n = n // 2
    for i in range(3, int(math.sqrt(n))+1, 2):
        while n % i == 0:
            arr.append(i)
            n = n // i
    if n > 2:
        arr.append(n)

    return arr


N = 100
l = [0 for x in range(N)]

for i in range(2, N):
    for j in range(2, N):
        required = i*j
        if(required < 100):
            l[required] = primeFactors(required)

for i in range(3, 100):
    if(l[i] == 0):
        print(i, primeFactors(i))
