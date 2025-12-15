#!/usr/bin/python3
import sys


def is_safe(queens, row, col):
    """
    Determines if a queen can be placed at (row, col) without being attacked
    by any queen already in the 'queens' list.
    """
    for r, c in queens:
        if c == col:
            return False
        if abs(row - r) == abs(col - c):
            return False
    return True


def solve_nqueens(n, row, queens):
    """
    Recursively solves the N Queens problem using backtracking.
    Args:
        n (int): The size of the board (NxN).
        row (int): The current row we are trying to place a queen in.
        queens (list): A list of [row, col] pairs for already placed queens.
    """

    if row == n:
        print(queens)
        return

    for col in range(n):
        if is_safe(queens, row, col):
            solve_nqueens(n, row + 1, queens + [[row, col]])


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)


    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(n, 0, [])


if __name__ == "__main__":
    main()
