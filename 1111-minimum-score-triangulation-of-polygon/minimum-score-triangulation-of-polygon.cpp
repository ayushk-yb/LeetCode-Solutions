class Solution {
public:
    // int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    // {
    //     if(i == j)
    //         return 0;
        
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
        
    //     int mini = 1e9;
    //     for(int k = i; k < j; k++)
    //     {
    //         int operations = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
    //         mini = min(mini, operations);
    //     }
        
    //     return dp[i][j] = mini;
    // }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // return solve(1, n - 1, values, dp);
        for(int i = n - 1; i >= 1; i--)
        {
            for(int j = i + 1; j < n; j++)
            {
                int mini = 1e9;
                for(int k = i; k < j; k++)
                {
                    int tri = (values[i - 1] * values[k] * values[j]) + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, tri);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }
};