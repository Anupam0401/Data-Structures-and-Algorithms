# We are given a two-dimensional board of size N x M (N rows and M
# columns). Each field of the board can be empty ('.'), may contain an obstacle
# ('x') or may have a character in it. The character might be either an assassin
# ('A') or a guard. Each guard stands still and looks straight ahead, in the
# direction they are facing.
# Every guard looks in one of four directions (up, down, left or right on the
# board) and is represented by one of four symbols. A guard denoted by '<' is
# looking to the left; by '>', to the right; "^", up; or 'v', down. The guards can see
# everything in a straight line in the direction in which they are facing, as far as
# the first obstacle (X or any other guard) or the edge of the board.

# The assassin can move from the current field to any other empty field with a
# shared edge. The assassin cannot move onto fields containing obstacles or
# enemies.

# Write a function:
# def solution (B)
# that, given an array B consisting of N strings denoting rows of the array,
# returns True if is it possible for the assassin to sneak from their current
# location to the bottom-right cell of the board undetected, and False
# otherwise.

# Example: Given B=["X.....>",..v..X.",".>..X..","A......"], the function should return False.

def solution(B):
    N = len(B)
    M = len(B[0])
    assassin = None
    guards = []
    obstacles = ['X', 'v', '^', '>', '<']
    # mark all the rows in the direcction of '>' and '<' as 'o'
    for i in range(N):
        for j in range(M):
            if B[i][j] == 'A':
                assassin = (i, j)
            if B[i][j] == 'v' or B[i][j] == '^':
                guards.append((i, j))
            if B[i][j] == '<' :
                for k in range(j, -1, -1):
                    if B[i][k] in obstacles and B[i][k] != '<':
                        break
                    B[i] = B[i][:k] + 'o' + B[i][k + 1:]
            if B[i][j] == '>':
                for k in range(j, M):
                    if B[i][k] in obstacles and B[i][k] != '>':
                        break
                    B[i] = B[i][:k] + 'o' + B[i][k + 1:]
    # mark all the columns in the direcction of 'v' and '^' as 'o'
    for j in range(M):
        for i in range(N):
            if B[i][j] == 'v':
                for k in range(i, N):
                    if B[k][j] in obstacles and B[k][j] != 'v':
                        break
                    B[k] = B[k][:j] + 'o' + B[k][j + 1:]
            if B[i][j] == '^':
                for k in range(i, -1, -1):
                    # break if B[k][j] is in obstacle except '^'
                    if B[k][j] in obstacles and B[k][j] != '^':
                        break
                    B[k] = B[k][:j] + 'o' + B[k][j + 1:]
    print(B)
    # print(assassin)
    # make all the 
    # perform a dfs to check if assassin can reach the bottom right corner
    def dfs(i, j):
        if i < 0 or i >= N or j < 0 or j >= M or B[i][j] == 'X' or B[i][j] == 'o':
            return False
        if i == N - 1 and j == M - 1:
            return True
        
        B[i] = B[i][:j] + 'o' + B[i][j + 1:]
        return dfs(i + 1, j) or dfs(i - 1, j) or dfs(i, j + 1) or dfs(i, j - 1)
    if assassin is None:
        return False
    return dfs(assassin[0], assassin[1])

print(solution(['...', '>.A']))