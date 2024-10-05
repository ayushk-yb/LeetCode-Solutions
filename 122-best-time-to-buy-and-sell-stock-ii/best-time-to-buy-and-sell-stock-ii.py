class Solution(object):
    def maxProfit(self, prices):
        maxProf = 0
        buy = float('inf')

        for i in range(len(prices)):
            if buy < prices[i]:
                maxProf += prices[i] - buy
                buy = prices[i]
            else:
                buy = prices[i]
            
        return maxProf
        