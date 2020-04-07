class Solution:
    def countElements(self, arr: List[int]) -> int:
        l = [0 for x in range(1001)]
        # print(l)
        for ele in arr:
            l[ele] += 1
        
        total = 0
        for i in range(0,1000):
            if(l[i+1]!=0):
                total += l[i]                
        return total
        
        