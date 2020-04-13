class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        zeros = [0 for i in range(n+1)]
        ones = [0 for i in range(n+1)]

        for i in range(n):
        	zeros[i+1] = zeros[i] + (1 - nums[i])

        for i in range(n):
        	ones[i+1] = ones[i] + (nums[i])


        max_length = 0
        for i in range(n):
            for j in range(i, n):
                total_ones = ones[j+1] - ones[i]
                total_zeros = zeros[j+1] - zeros[i]
                if(total_zeros == total_ones):
                    max_length = max(max_length, 2*total_zeros)
                    
        return max_length

# optimised
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        zeros = [0 for i in range(n+1)]
        ones = [0 for i in range(n+1)]

        for i in range(n):
        	zeros[i+1] = zeros[i] + (1 - nums[i])

        for i in range(n):
        	ones[i+1] = ones[i] + (nums[i])


        max_length = 0
        for i in range(n):
            for j in range(i, n):
                total_ones = ones[j+1] - ones[i]
                total_zeros = zeros[j+1] - zeros[i]
                if(total_zeros == total_ones):
                    max_length = max(max_length, 2*total_zeros)
                    
        return max_length

# optimised

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        d = {}   
        curr_sum = 0 
        max_len = 0 
        ending_index = -1 
  
        for i in range (0, n):  
            if(nums[i] == 0):  
                nums[i] = -1 
            else:  
                nums[i] = 1 

        for i in range (0, n):  
            curr_sum = curr_sum + nums[i]  
            if (curr_sum == 0):  
                max_len = i + 1 
                ending_index = i  
            if curr_sum in d: 
                if max_len < i - d[curr_sum]: 
                    max_len = i - d[curr_sum] 
                    ending_index = i 
            else:  
                d[curr_sum] = i   
          
        for i in range (0, n):  
            if(nums[i] == -1):  
                nums[i] = 0 
            else:  
                nums[i] = 1 
        return max_len