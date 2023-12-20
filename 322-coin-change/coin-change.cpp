class Solution {
public:
    int solve(int idx, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(idx == 0)
        {
            if(k % arr[idx] == 0)
                return k / arr[idx];
            
            return 1e9;
        }
        

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int not_take = solve(idx - 1, k, arr, dp);
        int take = 1e9;
        if(arr[idx] <= k)
            take = 1 + solve(idx, k - arr[idx], arr, dp);

        return dp[idx][k] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int res = solve(n - 1, amount, coins, dp);
        return (res == 1000000000) ? -1 : res;
    }
};
