class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &arr, int n, vector<vector<int>> &dp)
    {
        if(i == n - 1)
            return arr[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = arr[i][j] + solve(i + 1, j, arr, n, dp);
        int dia = arr[i][j] + solve(i + 1, j + 1, arr, n, dp);

        return dp[i][j] = min(down, dia);
        }
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1)
            return *min_element(triangle[0].begin(), triangle[0].end());
        
        int n = triangle.size();
        vector<int> next(n, -1);
        for(int j = 0; j < n; j++)
        {
           next[j] = triangle[n - 1][j];
        }

        for(int i = n - 2; i>= 0; i--)
        {
            vector<int> curr(n, 0);
            for(int j = 0; j <= i; j++)
            {
                int down = triangle[i][j] + next[j];
                int dia = triangle[i][j] + next[j + 1];

                curr[j] = min(down, dia);
            }

            next = curr;
        }
	    // return solve(0, 0, triangle, n, dp);

        return next[0];
    }
};