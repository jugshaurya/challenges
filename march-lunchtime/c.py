# https://www.codechef.com/LTIME82
t = int(input())

while(t):

    arr = [int(x) for x in input().split()]
    A = arr[0]
    B = arr[1]

    a = A // 10
    b = A % 10
    c = B // 10
    d = B % 10
    if(A < 10 and B < 10):
        print(A + B)
    # elif(A < 10 and B >= 10):
    #     print(max(c+b*10+d, d+c*10+b, b+c*10+d))
    # elif(B < 10 and A >= 10):
    #     print(max(a+b*10+d, d+b*10+a, a+d*10+b))
    else:
        print(max(d*10+b+c*10+a, c*10+b+a*10+d, a*10+c+b*10+d, a*10+d+c*10+b))
    t -= 1
