# https://www.codechef.com/COOK116B/problems/GIFTSRC
# cook your dish here


t = int(input())
while(t):
    n = input()
    arr = input()
    xmov = 0
    ymov = 0

    if(arr[0] == "L"):
        xmov -= 1
    elif(arr[0] == "R"):
        xmov += 1
    elif(arr[0] == "U"):
        ymov += 1
    else:
        ymov -= 1

    for i in range(1, len(arr)):
        if(arr[i-1] in "LR" and arr[i] in "LR"):
            continue
        if(arr[i-1] in "UD" and arr[i] in "UD"):
            continue
        if(arr[i] == "L"):
            xmov -= 1
        elif(arr[i] == "R"):
            xmov += 1
        elif(arr[i] == "U"):
            ymov += 1
        else:
            ymov -= 1

    print(xmov, ymov)
    t -= 1
