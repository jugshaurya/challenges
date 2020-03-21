#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'countPatterns' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER n as parameter.
#

# math - answer 24^n + 18*3^n + 9*2^n - 9*8^n + - 24
def countPatterns(n):
    # Write your code here
    mod = int(1e9+7)
    return int((pow(24, n, mod) % mod + (18*pow(3, n, mod)) % mod + (9*pow(2, n, mod)) % mod - (9*pow(8, n, mod)) % mod + - 24) % (1e9+7))


if __name__ == '__main__':
