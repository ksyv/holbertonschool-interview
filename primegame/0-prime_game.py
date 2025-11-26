#!/usr/bin/python3
"""
Module 0-prime_game
"""


def isWinner(x, nums):
    """
    Determines the winner of the prime game
    """
    if not nums or x < 1:
        return None

    max_n = max(nums)
    filter_is_prime = [True for _ in range(max(max_n + 1, 2))]
    filter_is_prime[0] = False
    filter_is_prime[1] = False

    for i in range(2, int(max_n ** 0.5) + 1):
        if filter_is_prime[i]:
            for j in range(i * i, max_n + 1, i):
                filter_is_prime[j] = False

    primes_count = [0] * (max_n + 1)
    count = 0
    for i in range(len(filter_is_prime)):
        if filter_is_prime[i]:
            count += 1
        primes_count[i] = count

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if primes_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
