class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string> &board)
    {
        if(row == 0 && col == 0)
            return true;
        
        int r = row;
        int c = col;
        while(r >= 0 && c >= 0)
        {
            if(board[r][c] == 'Q')
                return false;
            
            r--;
            c--;
        }
        r = row, c= col;
        while(c >= 0)
        {
            if(board[r][c] == 'Q')
                return false;
            
            c--;
        }
        c = col;
        while(r < n && c >= 0)
        {
            if(board[r][c] == 'Q')
                return false;
            
            r++;
            c--;
        }

        return true;
    }
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &res)
    {
        if(col == n)
        {
            res.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++)
        {
            if(isSafe(row, col, n, board))
            {
                board[row][col] = 'Q';
                solve(col + 1, n, board, res);
                board[row][col] = '.';
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
        solve(0, n, board, res);
        return res;
    }
};