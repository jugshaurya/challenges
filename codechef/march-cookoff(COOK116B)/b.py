# cook your dish here
t = int(input())
while(t):
    n = input()
    arr = input()
    xmov = 0
    ymov = 0

    if(arr[0] in "LR"):
        current = "x"
        if(arr[0] == "L"):
            xmov -= 1
        else:
            xmov += 1
    else:
        current = "y"
        if(arr[0] == "D"):
            ymov -= 1
        else:
            ymov += 1

    for i in range(1, len(arr)):
        if(arr[i] in "LR" and current == "x"):
            continue
        elif arr[i] in "UD" and current == "y":
            continue
        elif arr[i] in "LR" and current != "x":
            current = "x"
            if(arr[i] == "L"):
                xmov -= 1
            else:
                xmov += 1
        else:
            current = "y"
            if(arr[i] == "U"):
                ymov += 1
            else:
                ymov -= 1

    print(xmov, ymov)

    t -= 1
