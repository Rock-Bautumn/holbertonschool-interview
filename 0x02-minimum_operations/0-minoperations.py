#!/usr/bin/python3
"""This script finds the lowest number of operations (see readme)"""


def minOperations(n):
    """Find the lowest number of operations"""

    factor = 2
    fac_sum = 0
    result = 0

    if n < 2:
        return 0

    while (n % factor > 0):
        factor += 1

    while (n % factor == 0):
        result += 1
        fac_sum += factor - 1
        n /= factor
        if (n == 1):
            return result + fac_sum
        while (n % factor > 0):
            factor += 1

    return result
