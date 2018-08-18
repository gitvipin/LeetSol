#!/bin/env/python



def helper(grid, refs, sols, visited, i, j, word):

    if visited[i][j]:
        return

    word += grid[i][j]
    visited[i][j] = True

    if word in refs:
        sols.append(word)

    rows = len(grid)
    cols = len(grid[0])

    # change rows
    if i+1 >= 0 and i+1 < rows:
        helper(grid, refs, sols, visited, i+1, j, word)
    if i-1 >= 0 and i-1 < rows:
        helper(grid, refs, sols, visited, i-1, j, word)

    # change columns
    if j+1 >= 0 and j+1 < cols:
        helper(grid, refs, sols, visited, i, j+1, word)
    if j-1 >= 0 and j-1 < cols:
        helper(grid, refs, sols, visited, i, j-1, word)

    visited[i][j] = False


def boggle(grid, refs):
    sols = []
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            word = ""
            visited = [ [False for _ in range(cols)] for _ in range(rows)]
            helper(grid, refs, sols, visited, i, j, word)

    return sols

if __name__ == '__main__':
    grid = [
            ['C', 'O', 'P'],
            ['A', 'T', 'Y'],
            ['S', 'K', 'Q']
            ]
    refs = ["CAT", "ASK", "COPY"]

    # should find all - CAT , ASK , COPY
    print boggle(grid, refs)

    grid[1][0] = 'O'
    # should find COPY only
    print boggle(grid, refs)

    grid[1][0] = 'A'
    grid[1][1] = 'R'
    # should find COPY and CATonly
    print boggle(grid, refs)

