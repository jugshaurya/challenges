#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'commonPrefix' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING_ARRAY inputs as parameter.
#

def commonPrefix(inputs):
    # Write your code here
    ans = []
    for string in inputs:
        all_string = []
        filler = [0]*len(string)
        for i in range(len(string)):
            all_string.append(string[i:])

            # print("sd", all_string)
        for k in range(len(all_string)):
            sub = all_string[k]
            length = 0
            for i in range(len(sub)):
                if(sub[i] == string[i]):
                    length += 1
                else:
                    break
            filler[k] = length
            # print(length)

        summ = 0
        for ele in filler:
            summ += ele
        ans.append(summ)
    return ans


if __name__ == '__main__':
