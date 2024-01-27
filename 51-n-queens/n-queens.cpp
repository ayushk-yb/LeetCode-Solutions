class Solution {
public:
    // bool isSafe(int row, int col, int n, vector<string> &board)
    // {
    //     if(row == 0 && col == 0)
    //         return true;
        
    //     int r = row;
    //     int c = col;
    //     while(r >= 0 && c >= 0)
    //     {
    //         if(board[r][c] == 'Q')
    //             return false;
            
    //         r--;
    //         c--;
    //     }
    //     r = row, c= col;
    //     while(c >= 0)
    //     {
    //         if(board[r][c] == 'Q')
    //             return false;
            
    //         c--;
    //     }
    //     c = col;
    //     while(r < n && c >= 0)
    //     {
    //         if(board[r][c] == 'Q')
    //             return false;
            
    //         r++;
    //         c--;
    //     }

    //     return true;
    // }
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &res,
    vector<int> &leftRow, vector<int> &upperDia, vector<int> &lowerDia)
    {
        if(col == n)
        {
            res.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++)
        {
            // if(isSafe(row, col, n, board))
            // {
            //     board[row][col] = 'Q';
            //     solve(col + 1, n, board, res);
            //     board[row][col] = '.';
            // }
            if(leftRow[row] == 0 && upperDia[(n - 1) + (col - row)] == 0 
            && lowerDia[row + col] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDia[row + col] = 1;
                upperDia[(n - 1) + (col - row)] = 1;
                solve(col + 1, n, board, res, leftRow, upperDia, lowerDia);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDia[row + col] = 0;
                upperDia[(n - 1) + (col - row)] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> leftRow(n, 0), upperDia(2 * n - 1, 0), lowerDia(2 * n - 1, 0);
        solve(0, n, board, res, leftRow, upperDia, lowerDia);
        return res;
    }
};