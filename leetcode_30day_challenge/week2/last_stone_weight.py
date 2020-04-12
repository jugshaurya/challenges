from heapq import heapify, heappush, heappop;

class Solution:

    def lastStoneWeight(self, stones: List[int]) -> int:
        times = len(stones) - 1
        negStones = [(-1*ele) for ele in stones]
        heapify(negStones) #minheap
        heap = negStones
        while(len(negStones)>=2):
    
            firstMax = -1*heappop(heap)
            secondMax = -1*heappop(heap)

            if(firstMax == secondMax):
                continue
            else:
                # second < first
                heappush(heap, -1*(firstMax - secondMax))
        
        if(len(negStones)==0):
            return 0
        else:
            return -1*negStones[0]
        