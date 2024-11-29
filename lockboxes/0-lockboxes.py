#!/usr/bin/python3
'''module for check this:
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.'''


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

