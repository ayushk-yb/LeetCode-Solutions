class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int dfs(int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>> &dp)
    {
        if(dp[i][j] != 0)
            return dp[i][j];
        
        int path = 1;
        for(int x = 0; x < 4; x++)
        {
            int row = i + dx[x];
            int col = j + dy[x];

            if(row >= 0 && row < n && col >= 0 && col < m && matrix[row][col] > matrix[i][j])
            {
                path = max(path, 1 + dfs(row, col, n, m, matrix, dp));
            }
        }
        dp[i][j] = path;
        return path;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxSum = 1;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                maxSum = max(maxSum, dfs(i, j, n, m, matrix, dp));
            }
        }
        return maxSum;
    }
};