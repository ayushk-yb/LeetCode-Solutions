class Solution {
public:
    int solve(int i, int n, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(i == n - 1){
            if(amount % coins[i] == 0){
                return amount / coins[i];
            }

            return 1e9;
        }
        
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int take = 1e9;
        if(amount >= coins[i]){
            take = 1 + solve(i, n, coins, amount - coins[i], dp);
        }
        int notTake = solve(i + 1, n, coins, amount, dp);

        return dp[i][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = solve(0, n, coins, amount, dp);

        return (res == 1e9) ? -1 : res;
    }
};