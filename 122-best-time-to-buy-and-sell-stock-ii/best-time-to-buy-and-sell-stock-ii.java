class Solution {
    public int solve(int i, int[] prices, int n, int buyFlag, int[][] dp){
        if(i == n){
            return 0;
        }

        if(dp[i][buyFlag] != -1){
            return dp[i][buyFlag];
        }

        if(buyFlag == 1){
            int buy = solve(i + 1, prices, n, 0, dp) - prices[i];
            int notBuy = solve(i + 1, prices, n, 1, dp);

            return dp[i][buyFlag] = Math.max(buy, notBuy);
        }
        else{
            int sell = solve(i + 1, prices, n, 1, dp) + prices[i];
            int notSell = solve(i + 1, prices, n, 0, dp);

            return dp[i][buyFlag] = Math.max(sell, notSell);
        }
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int dp[][] = new int[n + 1][2];
        for(int i = 0;  i <= n; i++){
            for(int j = 0; j < 2; j++){
                dp[i][j] = -1;
            }
        }
        return solve(0, prices, n, 1, dp);
    }
}