#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'fewestCoins' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING coins as parameter.
#

def fewestCoins(coins):
    #  get the pattern
    pattern = ""
    for ele in coins:
        if(ele in pattern):
            pass
        else:
            pattern += ele
    # print(pattern)
    # corner case
    if(len(coins) < len(pattern)):
        return 0

    pattern_arr = [0] * 256
    coins_arr = [0] * 256
    for i in range(len(pattern)):
        pattern_arr[ord(pattern[i])] += 1

    start = 0
    ptr = -1
    min_len = 1e5+5
    j = 0
    for i in range(len(coins)):
        val = ord(coins[i])
        coins_arr[val] += 1
        if(pattern_arr[val] != 0 and coins_arr[val] <= pattern_arr[val]):
            j += 1
        if(j == len(pattern)):
            while(coins_arr[ord(coins[start])] > pattern_arr[ord(coins[start])] or pattern_arr[ord(coins[start])] == 0):
                if(coins_arr[ord(coins[start])] > pattern_arr[ord(coins[start])]):
                    coins_arr[ord(coins[start])] -= 1
                start += 1

            curr_len = i - start + 1
            if(min_len > curr_len):
                min_len = curr_len
                ptr = start

    # if ptr doesn't changes
    if(ptr == -1):
        return 0
    return min_len


if __name__ == '__main__':
