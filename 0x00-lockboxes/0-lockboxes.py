#!/usr/bin/python3
"""Check if all boxes can be opened with keys"""

def canUnlockAll(boxes):
    """Check the boxes for all potential keys"""

    keys = range(1, len(boxes) - 1)
    for key in keys:
        if any(key in sl for sl in boxes) == False:
            return False
    return True
