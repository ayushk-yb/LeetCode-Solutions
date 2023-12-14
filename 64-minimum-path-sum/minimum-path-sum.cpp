class Solution
{
    public:
        int solve(vector<vector < int>> &grid, int i, int j, vector< vector< int>> &dp)
        {
            if (i == 0 && j == 0)
                return grid[i][j];

            if (i < 0 || j < 0)
                return 1e9;

            if (dp[i][j] != -1)
                return dp[i][j];

            int up = grid[i][j] + solve(grid, i - 1, j, dp);
            int left = grid[i][j] + solve(grid, i, j - 1, dp);

            return dp[i][j] = min(up, left);
        }

    int minPathSum(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m, 0);

        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = grid[0][0];
                }
                else
                {
                    int up = 1e9;
                    int left = 1e9;
                    if (i - 1 >= 0)
                    {
                        up = grid[i][j] + prev[j];
                    }
                    if (j - 1 >= 0)
                    {
                        left = grid[i][j] + temp[j - 1];
                    }
                    temp[j] = min(up, left);
                }
            }
            prev = temp;
        }

        return prev[m - 1];
    }
};