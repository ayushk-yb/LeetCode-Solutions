class Solution {
public:
    int solve(int row, int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>> & moveCost, vector<vector<int>> &dp)
    {
        if(row >= n || col >= m)
            return 1e9;
        
        if(row == n - 1)
            return grid[row][col];
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int ans = 1e9;
        for(int i = 0; i < m; i++)
        {
            int val = grid[row][col];
            int cost = moveCost[val][i];

            ans = min(ans, val + cost + solve(row + 1, i, n, m, grid, moveCost, dp));
        }

        return dp[row][col] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 1e9;
        for(int col = 0; col < m; col++)
        {
            ans = min(ans, solve(0, col, n, m, grid, moveCost, dp));
        }
        return ans;
    }
};