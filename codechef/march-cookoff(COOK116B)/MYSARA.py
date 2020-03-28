t = int(input())
while(t):
    n = int(input())
    bArr = [int(x) for x in input().split()]
    valid = True
    for i in range(1, len(bArr)):
        if(bArr[i] & bArr[i-1] != bArr[i-1]):
            valid = False

    if(not valid):
        print(0)
        t -= 1
        continue

    # 1*2^(set bits in B(1))*2^(set bits in B(2))*...*2^(set bits in B(n-1))
    mod = 10**9+7
    total_ways = 1
    for i in range(1, len(bArr)):
        setbitsCount = bin(bArr[i-1]).count("1")
        total_ways = (total_ways * pow(2, setbitsCount, mod)) % mod

    print(total_ways % mod)
    t -= 1
