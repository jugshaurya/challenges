
# cook your dish here
from heapq import heapify, heappop, heappush

t = int(input())
tc = t
while(t):
    n, k = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    d = {}
    for i in range(1, n):
        diff = arr[i-1] - arr[i]
        if(diff in d):
            d[diff].append((arr[i], arr[i-1]))
        else:
            d[diff] = [(arr[i], arr[i-1])]

    heap = list(d.keys())
    heapify(heap)
    session = 0
    while(session < k):
        session += 1
        max_value = heap[0]
        if(len(d[max_value]) == 1):
            b, a = d[max_value][0]
            del d[max_value]
            heappop(heap)
        else:
            b, a = d[max_value].pop()

        mid = (b+a)//2
        diff_left = (a-mid)
        diff_right = (mid-b)

        if(diff_left not in heap):
            heappush(heap, diff_left)
        if(diff_left not in heap):
            heappush(heap, diff_right)

        if(diff_left in d):
            d[diff_left].append((mid, a))
        else:
            d[diff_left] = [(mid, a)]

        if(diff_right in d):
            d[diff_right].append((b, mid))
        else:
            d[diff_right] = [(b, mid)]
        
    t -= 1
    print(f"case #{tc-t}: {-heap[0]}")
