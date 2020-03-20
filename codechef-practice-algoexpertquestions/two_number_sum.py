n = int(input())
arr = [int(x) for x in input().split()]
target = int(input())
gotcha = False


def printways(arr, i, target, ans):
    if(target < 0 or i >= len(arr)):
        return

    if(target == 0):
        global gotcha
        gotcha = True
        print(*ans)
        return

    # once take the first element
    ans.append(arr[i])
    printways(arr, i, target-arr[i], ans)
    ans.pop()

    # once don't
    printways(arr, i+1, target, ans)


ans = []
arr.sort()
printways(arr, 0, target, ans)
if(not gotcha):
    print('"G@me |0$t"')
