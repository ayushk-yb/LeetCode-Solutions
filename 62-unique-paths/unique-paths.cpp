class Solution
{
    public:
        int solve(int i, int j, vector<vector < int>> &dp)
        {
            if (dp[i][j] != -1)
                return dp[i][j];

            if (i == 0 || j == 0)
                return 1;

            if (i < 0 || j < 0)
                return 0;

            return dp[i][j] = solve(i - 1, j, dp) + solve(i, j - 1, dp);
        }
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 1);
        // return solve(m - 1, n - 1, dp);

        // for(int i = 0; i < m; i++)
        // {
        //     dp[i][0] = 1;
        // }

        // for(int i = 0; i < n; i++)
        // {
        //     dp[0][i] = 1;
        // }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};