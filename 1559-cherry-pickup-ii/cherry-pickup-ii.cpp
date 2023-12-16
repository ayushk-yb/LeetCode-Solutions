class Solution {
public:
    int solve(int r, int c1, int c2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if(c1 < 0 || c2 >= m || c2 < 0 || c1 >= m)
            return -1e8;
        
        if(r == n - 1)
        {
            int ans = grid[r][c1];
            if(c1 != c2)
                ans += grid[r][c2];
            
            return ans;
        }
        
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        
        int maxi = -1;
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                int ans = grid[r][c1] + solve(r + 1, c1 + i, c2 + j, n, m, grid, dp);
                if(c1 != c2)
                    ans += grid[r][c2];
                
                maxi =  max(maxi, ans);
            }
        }

        return dp[r][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));

        return solve(0, 0, col - 1, row, col, grid, dp);
    }
};