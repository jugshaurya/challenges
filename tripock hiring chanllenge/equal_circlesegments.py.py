#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'largestSegment' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. INTEGER_ARRAY radius
#  2. INTEGER segments
#

def isPossible(mid, areas, segments):
    total = 0
    for ele in areas:
        possible_number_of_segments = ele//mid
        total += possible_number_of_segments
    # print("sjdlasflashfka", total)
    if(total >= segments):
        return True
    return False


def largestSegment(radius, segments):
    PI = 3.14159265359
    precision = 0.0001
    areas = [PI*ele*ele for ele in radius]

    # if(right-left<=precision):
    #     return str(round(left/segments,5))
    # if all elements are same thne return areas[i]*n/seg-length

    all_same = True
    for i in range(1, len(areas)):
        if(areas[i-1] != areas[i]):
            all_same = False

    if(all_same):
        return str(round(areas[0]*len(areas)/segments, 5))

    left = 0
    right = max(areas)
    possible_ans = left
    while(left <= right):
        mid = (left+right) / 2
        if(isPossible(mid, areas, segments)):
            possible_ans = mid
            # print("poss", possible_ans)
            left = mid+precision
        else:
            right = mid - precision

    return str(round(possible_ans, 5))
    # Write your code here
