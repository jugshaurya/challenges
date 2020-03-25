# https://www.codechef.com/COOK116B/problems/CHCBOX
# cook your dish here


def getNumberofWays(arr, n, maxi):
    max_arr = []
    for i, ele in enumerate(arr):
        if(ele == maxi):
            max_arr.append(i)

    total_ways = 0
    for i in range(1, len(max_arr)):
        number_in_btw = max_arr[i] - max_arr[i-1] - 1
        if(number_in_btw >= n//2):
            total_ways += number_in_btw - n//2 + 1

    number_in_btw = n - 1 - max_arr[-1] + max_arr[0]
    if(number_in_btw >= n//2):
        total_ways += number_in_btw - n//2 + 1

    return total_ways


t = int(input())
while(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(getNumberofWays(arr, n, max(arr)))
    t -= 1
