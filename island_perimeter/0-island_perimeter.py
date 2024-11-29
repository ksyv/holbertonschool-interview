#!/usr/bin/python3
'''module for find the island perimeter'''


def island_perimeter(grid):
    '''calc the island perimeter'''

    if grid is None or len(grid) == 0:
        return 0
    rows = len(grid)
    columns = len(grid[0])
    perimeter = 0
    for row in range(rows):
        for column in range(columns):
            if grid[row][column] == 1:
                if row == 0 or grid[row - 1][column] == 0:
                    perimeter += 1
                if row == rows - 1 or grid[row + 1][column] == 0:
                    perimeter += 1
                if column == 0 or grid[row][column - 1] == 0:
                    perimeter += 1
                if column == columns - 1 or grid[row][column + 1] == 0:
                    perimeter += 1
    return perimeter
