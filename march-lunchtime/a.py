
def SieveOfEratosthenes(n):

    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1
    prime[0] = False
    prime[1] = False

    ans = []
    for p in range(n + 1):
        if prime[p]:
            ans.append(p)

    return ans


t = int(input())
primes = SieveOfEratosthenes(10005)
while(t):

    n, m = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    local_primes = []
    for i in primes:
        if(i <= m):
            local_primes.append(i)

    if(len(local_primes) == 0):
        print(1)
        t -= 1
        continue

    not_in = []
    for i in local_primes:
        if(i not in arr):
            not_in.append(i)

    if(len(not_in) == 0):
        print(1)
    else:
        print(not_in[-1])
    t -= 1
