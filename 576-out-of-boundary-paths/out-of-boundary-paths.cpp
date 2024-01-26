class Solution {
public:
    int solve(int i, int j, int m, int n, int moves, vector<vector<vector<int>>> &dp)
    {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return 1;

        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];

        int up = 0, down = 0, left = 0, right = 0;
        if(moves > 0)
            up = solve(i - 1, j, m, n, moves - 1, dp);
        if(moves > 0)
            down = solve(i + 1, j, m, n, moves - 1, dp);
        if(moves > 0)
            left = solve(i, j - 1, m, n, moves - 1, dp);
        if(moves > 0)
            right = solve(i, j + 1, m, n, moves - 1, dp);
        
        return dp[i][j][moves] = ((up + down) % 1000000007 + (left + right) % 1000000007) % 1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(startRow, startColumn, m, n, maxMove, dp);
    }
};