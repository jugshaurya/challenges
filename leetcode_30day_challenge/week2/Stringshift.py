class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        
        totalShift = 0
        for ele in shift:
            dire = ele[0]
            amount = ele[1]
            if(dire == 0):
                # left shift
                totalShift -= amount
            else:
                # right shift
                totalShift += amount
                
        orig_s = [ele for ele in s]
        n = len(s)
        print(totalShift)
        if (totalShift > 0):
            totalShift %= n
            # shift right
            result = orig_s[n-totalShift: ]
            result.extend(orig_s[:n-totalShift])
            return "".join(result)
        elif(totalShift < 0):
            # shift left
            totalShift = -1*totalShift
            totalShift %=n
            result = orig_s[totalShift:]
            result.extend(orig_s[:totalShift])
            return "".join(result)
        else:
            return s
