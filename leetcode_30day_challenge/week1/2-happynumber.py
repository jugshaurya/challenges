class Solution:
    def isHappy(self, n: int) -> bool:
        number = str(n)
        already_get = []
        while(True):
            square = 0
            for digit in number:
                int_digit = int(digit)
                square += int_digit*int_digit
            if(square == 1):
                return True
            else:
                if(square in already_get):
                    return False
                already_get.append(square)
                number = str(square)
