class Solution(object):
    def solve(self, i, prices, buy_flag, dp):
        if i == len(prices):
            return 0
        if dp[i][buy_flag] != None:
            return dp[i][buy_flag]
        if buy_flag:
            buy = self.solve(i + 1, prices, 0, dp) - prices[i]
            not_buy = self.solve(i + 1, prices, 1, dp)
            dp[i][buy_flag] = max(buy, not_buy)
            return dp[i][buy_flag]
        else:
            sell = self.solve(i + 1, prices, 1, dp) + prices[i]
            not_sell = self.solve(i + 1, prices, 0, dp)
            dp[i][buy_flag] = max(sell, not_sell)
            return dp[i][buy_flag]

    def maxProfit(self, prices):
        dp = [[None] * 2 for _ in range(len(prices))] 
        return self.solve(0, prices, 1, dp)
        