class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));
        // int res = solve(0, n, coins, amount, dp);
        for(int j = 0; j <= amount; j++){
            if(j % coins[n - 1] == 0){
                dp[n - 1][j] = j / coins[n - 1];
            }
        }
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j <= amount; j++){
                int take = 1e9;
                if(j >= coins[i]){
                    take = 1 + dp[i][j - coins[i]];
                }
                int notTake = dp[i + 1][j];

                dp[i][j] = min(take, notTake);              
            }
        }
        int res = dp[0][amount];
        return (res == 1e9) ? -1 : res;
    }
};