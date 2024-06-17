class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));
        // int res = solve(0, n, coins, amount, dp);
        vector<int> next(amount + 1, 1e9);
        vector<int> curr(amount + 1, 1e9);
        for(int j = 0; j <= amount; j++){
            if(j % coins[n - 1] == 0){
                next[j] = j / coins[n - 1];
            }
        }
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j <= amount; j++){
                int take = 1e9;
                if(j >= coins[i]){
                    take = 1 + curr[j - coins[i]];
                }
                int notTake = next[j];

                curr[j] = min(take, notTake);              
            }
            next = curr;
        }
        int res = next[amount];
        return (res == 1e9) ? -1 : res;
    }
};