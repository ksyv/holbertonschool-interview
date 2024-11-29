#!/usr/bin/python3
'''module for check this:
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.'''


def canUnlockAll(boxes):
    openedBox = []
    if (len(boxes) <= 0):
        return False
def canUnlockAll(boxes):
    if not boxes or len(boxes) == 0:
        return False

    n = len(boxes)
    visited = [False] * n
    visited[0] = True
    queue = [0]

    while queue:
        box_index = queue.pop(0)
        for key in boxes[box_index]:
            if key < n and not visited[key]:
                visited[key] = True
                queue.append(key)
    return all(visited)

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))
