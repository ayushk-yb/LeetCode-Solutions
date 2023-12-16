class Solution {
public:
    int solve(int r1, int c1, int r2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        int c2 = r1 + c1 - r2;

        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e8;
        
        if(r1 == n - 1 && c1 == n - 1) //equal steps by poth person to reach bottom right, so sec would have reached if first reached
            return grid[r1][c1];
        
        if(dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];
        
        int ans = grid[r1][c1];

        if(r1 != r2)
            ans += grid[r2][c2];
        
        int temp1 = solve(r1 + 1, c1, r2 + 1, n, grid, dp);
        int temp2 = solve(r1, c1 + 1, r2, n, grid, dp);
        int temp3 = solve(r1 + 1, c1, r2, n, grid, dp);
        int temp4 = solve(r1, c1 + 1, r2 + 1, n, grid, dp);

        int temp = max(max(temp1, temp2), max(temp3, temp4));


        ans += temp;
        
        return dp[r1][c1][r2] = ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

        return max(0, solve(0, 0, 0, n, grid, dp));
    }
};