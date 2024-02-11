class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(col, vector<int>(col, -1)));
        for(int c1 = 0; c1 < col; c1++)
        {
            for(int c2 = 0; c2 < col; c2++)
            {
                dp[r - 1][c1][c2] = grid[r - 1][c1];
                if(c1 != c2)
                    dp[r - 1][c1][c2] += grid[r - 1][c2];
            }
        }

        for(int row = r - 2; row >= 0; row--)
        {
            for(int c1 = 0; c1 < col; c1++)
            {
                for(int c2 = 0; c2 < col; c2++)
                {
                    int maxi = -1;
                    for(int i = -1; i <= 1; i++)
                    {
                        for(int j = -1; j <= 1; j++)
                        {
                            int newC1 = c1 + i;
                            int newC2 = c2 + j;
                            
                            if (newC1 >= 0 && newC1 < col && newC2 >= 0 && newC2 < col) 
                            {
                                int ans = grid[row][c1] + dp[row + 1][newC1][newC2];
                                if (c1 != c2) 
                                {
                                    ans += grid[row][c2];
                                }
                                dp[row][c1][c2] = max(dp[row][c1][c2], ans);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][col - 1];
        // return solve(0, 0, col - 1, r, col, grid, dp);
    }
};