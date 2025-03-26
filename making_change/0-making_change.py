#!/usr/bin/python3
"""
Module for makeChange function
"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given amount total
    using dynamic programming.
    """
    if total <= 0:
        return 0

    dp = [total + 1] * (total + 1)

    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount:
                if dp[amount - coin] != (total + 1):
                    dp[amount] = min(dp[amount], 1 + dp[amount - coin])

    if dp[total] == (total + 1):
        return -1
    else:
        return dp[total]
