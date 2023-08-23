#!/usr/bin/python3
"""Island perimeter module"""


def get(coords, direction):
    """get coordinates in the given direction"""
    if direction == 0:
        return (coords[0], coords[1] + 1)
    elif direction == 1:
        return (coords[0] + 1, coords[1])
    elif direction == 2:
        return (coords[0], coords[1] - 1)
    elif direction == 3:
        return (coords[0] - 1, coords[1])
    else:
        return None


def move(coords, direction):
    """move in a given direction"""
    if direction == 0:
        return (coords[0] + 1, coords[1])
    elif direction == 1:
        return (coords[0], coords[1] - 1)
    elif direction == 2:
        return (coords[0] - 1, coords[1])
    elif direction == 3:
        return (coords[0], coords[1] + 1)
    else:
        return None


def find_first(grid, xsize, ysize):
    """get the first 1 square"""
    for x in range(xsize):
        for y in range(ysize):
            if grid[x][y] == 1:
                return (x, y)

    return None


def island_perimeter(grid):
    """Get the perimeter of an island described in grid variable"""

    first = None
    current = None
    direction = None
    count = 0
    xsize = len(grid)
    ysize = len(grid[0])

    first = find_first(grid, xsize, ysize)
    if first is None:
        return 0

    current = first

    while current != first or direction != 0:
        if direction is None:
            direction = 0
        side = get(current, direction)
        if side[0] >= xsize or side[0] < 0 or side[1] >= ysize or side[1] < 0:
            sideval = 0
        else:
            sideval = grid[side[0]][side[1]]

        if sideval == 0:
            count = count + 1
            direction = (direction + 1) % 4
            continue
        elif sideval == 1:
            direction = (direction + 3) % 4
            current = move(current, direction)
        else:
            return None

    return count
