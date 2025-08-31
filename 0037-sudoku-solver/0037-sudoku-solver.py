class Solution(object):
    def solveSudoku(self, board):
        row = [[0] * 10 for _ in range(9)]
        col = [[0] * 10 for _ in range(9)]
        box = [[0] * 10 for _ in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    num = int(board[i][j])
                    row[i][num] = col[j][num] = box[(i//3)*3 + (j//3)][num] = 1

        def backtrack(i, j):
            if i == 9:
                return True
            if j == 9:
                return backtrack(i+1, 0)
            if board[i][j] != '.':
                return backtrack(i, j+1)

            for num in range(1, 10):
                box_idx = (i//3)*3 + (j//3)
                if not row[i][num] and not col[j][num] and not box[box_idx][num]:
                    board[i][j] = str(num)
                    row[i][num] = col[j][num] = box[box_idx][num] = 1

                    if backtrack(i, j+1):
                        return True

                    board[i][j] = '.'
                    row[i][num] = col[j][num] = box[box_idx][num] = 0

            return False

        backtrack(0, 0)
