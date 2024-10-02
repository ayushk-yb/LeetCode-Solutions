class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        buy = prices[0]
        maxProfit  = 0
        for i in range(len(prices)):
            if buy > prices[i]:
                buy = prices[i]
            
            maxProfit = max(maxProfit, prices[i] - buy)
        
        return maxProfit