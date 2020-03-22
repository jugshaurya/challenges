# cook your dish here


def alpha(n, arr):

    all_same = True
    for i in range(1, len(arr)):
        if(arr[i-1] != arr[i]):
            all_same = False

    if(all_same):
        return 0
    # find rightmost max
    maxi = max(arr)
    maxi_index = arr[::-1].index(maxi)
    start_index = arr.index(maxi)

    if(start_index+maxi_index < n//2):
        return 0
    # print("zxf", start_index)
    if(start_index > n//2):
        maxi_index += 1  # for k = 0
    return maxi_index


t = int(input())
while(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(alpha(n, arr))
    t -= 1
