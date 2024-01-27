class Solution {
public:
    // bool isSafe(char c, int row, int col, vector<vector<char>> &board)
    // {
    //     for(int i = 0; i < 9; i++)
    //     {
    //         if(board[i][col] == c)
    //             return false;
    //         if(board[row][i] == c)
    //             return false;
            
    //         int boxRow = 3 * (row / 3) + (i / 3);
    //         int boxCol = 3 * (col / 3) + (i % 3);
    //         if(board[boxRow][boxCol] == c)
    //             return false; 
    //     }

    //     return true;
    // }
    bool isSafe(char c, int row, int col, vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c || board[row][i] == c || board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {
                        if(isSafe(c, i, j, board))
                        {
                            board[i][j] = c;
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};