# https://www.codechef.com/LTIME82
t = int(input())


def getCount(string, d, k, x):
    count = 0
    alpha = k
    print(d, string)
    for ele in string:
        if(d[ele] <= x):
            print("p", ele, "p")
            count += 1
        elif(d[ele]-alpha <= x):
            alpha -= d[ele] - x
            print("saf", alpha)
            count += 1
        else:
            print("dfs", d[ele], ele, x)
            # break
            pass
    print(count)
    return count


while(t):

    string = input()
    arr = [int(x) for x in input().split()]
    k = arr[0]
    x = arr[1]

    d = {}
    for ele in string:
        if(ele in d):
            d[ele] += 1
        else:
            d[ele] = 1

    rev_string = string[::-1]
    result = 0
    n = len(string)
    for i in range(len(rev_string)):
        result = max(result, getCount(string[:n-i], d, k, x))
        d[rev_string[i]] -= 1
    print(result)
    t -= 1
