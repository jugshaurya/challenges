from math import sqrt, floor

N = 1000000
factors = [[] for i in range(0, N + 1)]

def sieveToGetFactorsArray():
    global factors
    global N
    for i in range(2, floor(sqrt(N))+1):
        if(len(factors[i]) == 0):
            for j in range(i, N, i):
                factors[j].append(i)

def main():
    global factors
    global N

    sieveToGetFactorsArray()
    t = int(input())
    while t:
        t -= 1
        n = int(input())
        if(n == 1):
            print(n)
            print(1, 1, sep=" ")
            continue

        done = [0 for i in range(n+1)]
        setArray = [set() for i in range(n//2)]
        result = []
        idx = -1
        for i in range(2, n+1, 2):
            idx += 1
            if(i == 2):
                done[1] = done[2] = 1
                result.append([1, 2])
                setArray[idx] = {2}

            else:
                done[i] = 1
                result.append([i])
                j_factors_set = set(factors[i])
                setArray[idx] = j_factors_set

        for i in range(3, n+1, 2):
            idx = 0
            j = i
            while(j < (n+1)):
                if(done[j] == 0):
                    j_factors_set = set(factors[j])
                    not_allowed_set = setArray[idx]
                    interSection = j_factors_set.intersection(not_allowed_set)
                    if(len(interSection) == 0):
                        result[idx].append(j)
                        done[j] = 1
                        idx += 1
                        for ele in j_factors_set:
                            setArray[idx-1].add(ele)
                    else:
                        # i can not put in here
                        if(idx == 0):
                            done[j] = 1
                            setArray[idx].add(j)  # optional
                            result[0].append(j)
                            idx += 1
                        else:
                            idx += 1
                            continue

                j += i

        print(len(result))
        for sub in result:
            print(len(sub),end=" ")
            for ele in sub:
                print(ele, end=" ")
            print()

main()
